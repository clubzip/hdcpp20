#include <iostream>
#include <coroutine>
#define log() std::cout << "==============> " << __func__ << std::endl 



template<typename T>
class Generator
{
public:
	class promise
	{
		T value;
	public:
		T get_value() const { return value; }

		std::suspend_always yield_value(int n)
		{
			value = n;
			log();
			return {};
		}

		//std::suspend_always initial_suspend()
		std::suspend_never initial_suspend()
		{
			log();
			return {};
		}
		std::suspend_always final_suspend() noexcept { log();  return {}; }

		Generator get_return_object()
		{
			auto h = std::coroutine_handle<promise_type>::
				from_promise(*this);
			log();
			return Generator(h);
		};

		void unhandled_exception() { log(); }
		void return_void() { log(); }
	};
	//--------------------------------------------------------
	// Generator 멤버 들
	using promise_type = promise;


	Generator(std::coroutine_handle<promise_type> h)
		:coro_handle(h)
	{
	}
	~Generator()
	{
		if (coro_handle)
			coro_handle.destroy();
	}

	T operator()()
	{
		if (coro_handle && !coro_handle.done())
		{
			coro_handle.resume();
			T ret = coro_handle.promise().get_value();

			return ret;
		}
		return 0;
	}

	Generator() = default;

	Generator(const Generator&) = delete;
	Generator& operator=(const Generator&) = delete;

	Generator(Generator&& other) : coro_handle(other.coro_handle)
	{
		other.coro_handle = {};
	}
	Generator& operator=(Generator&& other)
	{
		if (this == &other) return *this;

		if (coro_handle)
			coro_handle.destroy();

		coro_handle = other.coro_handle;
		other.coro_handle = {};

		return *this;
	}






private:
	std::coroutine_handle<promise_type> coro_handle;
};

//-----------------------------------



Generator<int> foo()
{
	//----------------------------------
	// 컴파일러가 생성한 코드
	// 
	// co_yield generator객체  인데.. 결국 아래의미가 됩니다.
	// 
	// ==> co_await pomise객체.initial_suspend()
	// ==>			즉, 이함수에 반환 값에 따라 중단여부 결정
	// 
	//----------------------------------
	std::cout << "foo 1" << std::endl;

	co_await std::suspend_always{}; 

	std::cout << "foo 2" << std::endl;
}
int main()
{
	Generator<int> g = foo();

	std::cout << "main 1" << std::endl;

	g();
	std::cout << "main 2" << std::endl;
	g();

	std::cout << "main 3" << std::endl;

}
