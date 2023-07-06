#include <iostream>
#include <coroutine>
#define log() std::cout << "==============> " << __func__ << std::endl 


// Step 6. 약간의 코드 개선
// => coroutine 핸들을 직접 노출하지 말고
// => operator() 연산자로.. 실행


class Generator
{
public:
	class promise
	{
	public:
		std::suspend_always initial_suspend()
		{
			log();
			return {};
		}
		std::suspend_always final_suspend() noexcept { log();  return {}; }

		// 코루틴이 시작될때 컴파일러가 추가한 코드가
		// Generator 를 만들기 위해 아래 함수 호출
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

	void operator()()
	{
		if (coro_handle && !coro_handle.done())
		{
			coro_handle.resume();
		}
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
	co_await std::suspend_always{};

	std::cout << "foo 2" << std::endl;
}

int main()
{
	Generator g = foo();	
	std::cout << "main 1" << std::endl;
	
	g();

	std::cout << "main 2" << std::endl;
	
	g();

	std::cout << "main 3" << std::endl;

}
