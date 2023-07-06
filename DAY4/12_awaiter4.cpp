#include <iostream>
#include <coroutine>
#include <thread>
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

struct resume_new_thread
{
	bool await_ready() const noexcept { log(); return false; }

	void await_suspend(std::coroutine_handle<> handle ) const noexcept 
	{ 
		log(); 

		// 새로운 스레드로 중단된 지점 이후를 실행
		std::thread t( [handle]() { handle.resume(); });
		t.detach();
	}

	void await_resume() const noexcept { log(); }
};




Generator<int> foo()
{
	std::cout << "foo 1 : " << std::this_thread::get_id() << std::endl;

	co_await resume_new_thread{};	// 주스레드는 main 으로 복귀!
									// 새로운 스레드로 나머지 작업 수행 

	std::cout << "foo 2 : " << std::this_thread::get_id() << std::endl;
}

int main()
{
	Generator<int> g = foo();

	std::cout << "main 1" << std::endl;

	g();

	std::cout << "main 2" << std::endl;

	getchar();
}
