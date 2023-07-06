#include <iostream>
#include <coroutine>
#define log() std::cout << __func__ << std::endl 


// Step 5. 코루틴 핸들이야기
// => 호출자(main) 은 코루틴의 핸들을 알아야 코루틴을 제어할수 있습니다.
// => 호출자(main) 이 얻게되는 것은 결국 Generator 객체 입니다.

// Generator 의 역할 : 코루틴의 반환 값
//					  => 대부분 코루틴의 핸들을 멤버로 가지게 됩니다.

// promise_type 의 역활 : 코루틴 실행중 발생하는 다양한 이벤트에 대한
//						 세부 제어를 하기 위한 클래스
//						 => 1번째 suspend, final suspend
//						 => 예외 처리, 반환값 처리



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
		Generator get_return_object() { log(); return {}; };
		void unhandled_exception() { log(); }
		void return_void() { log(); }
	};
	//--------------------------------------------------------
	// Generator 멤버 들
	using promise_type = promise;

	std::coroutine_handle<promise_type> coro_handle; // 멤버데이타

	Generator(std::coroutine_handle<promise_type> h)
		:coro_handle(h)
	{
	}

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
}
