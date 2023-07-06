#include <iostream>
#include <coroutine>
#define log() std::cout << "==============> " << __func__ << std::endl 


// Step 8. Generator 의 복사 생성자와 move 생성자 


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

		std::suspend_always initial_suspend()
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

	// 복사와 대입은 금지
	Generator(const Generator&) = delete;
	Generator& operator=(const Generator&) = delete;

	// move 와 move 대입은 허용
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


Generator<int> foo()
{
	//--------------------------
	// 컴파일러가 생성한 코드가 실행되고
	// 여기서 main 으로 돌아감..
	//--------------------------
	std::cout << "foo 1" << std::endl;

	co_yield 10;

	std::cout << "foo 2" << std::endl;

	co_yield 20;
}

int main()
{
	Generator<int> g = foo();
	
	// Generator 는 결국 "코루틴 핸들"을 가지고 
	// operator() 등을 통해서 실행 재개를 담당합니다.

//	Generator<int> g1 = g; // 안되는 것이 좋습니다.

	Generator<int> g2 = std::move(g); // 되는것이 좋습니다.

}
