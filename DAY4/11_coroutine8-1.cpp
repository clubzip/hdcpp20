#include <iostream>
#include <coroutine>
#define log() std::cout << "==============> " << __func__ << std::endl 


// Step 7. co_yield

// co_await : 실행을 멈추고(suspend) 호출자에 돌아갈때
// co_yield : ""					""	          값반환!

class Generator
{
public:
	class promise
	{
		int value;
	public:
		int get_value() const { return value; }

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

	int operator()()
	{
		if (coro_handle && !coro_handle.done())
		{
			coro_handle.resume(); // 실행재개 하고

			// 결과를 꺼내서 반환
			int ret = coro_handle.promise().get_value();

			return ret;
		}
		return 0;
	}

private:
	std::coroutine_handle<promise_type> coro_handle;
};


Generator foo()
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
	Generator g = foo();
	std::cout << "main 1" << std::endl;

	int ret1 = g(); 

	std::cout << "main 2" << std::endl;

	int ret2 = g();

	std::cout << "main 3" << std::endl;

}
