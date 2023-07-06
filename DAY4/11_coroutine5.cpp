#include <iostream>
#include <coroutine>

// C++ 코루틴은 어떻게 동작하는가 ?
// 원리를 살펴보는 코드..
// 주석을 잘 생각해보세요..

class Generator
{
public:

	class promise
	{
	public:
		std::suspend_always initial_suspend() { return {}; }
		std::suspend_always final_suspend() noexcept { return {}; }
		Generator get_return_object() { return {}; };
		void unhandled_exception() {}
		void return_void() {}
	};

	using promise_type = promise;
};


Generator foo()
{
	// 함수 안에 "co_await" 등의 키워드가 있으면 컴파일러가 아래 코드를 생성합니다.
	//---------------------------------------------
	// 1. 코루틴 frame 을 힙에 생성합니다.
	// => sizeof(지역변수) + sizeof(반환타입::promise_type) + 기타 정보 
	//		 => 지역변수가 없어도 200 ~ 400 byte 정도 컴파일러마다 다릅니다.

	// 2. promise_type 의 생성자 호출

	// 3. promise_type 의 get_return_objec()를 호출해서 Generator 생성

	// 4. promise_type 의 initial_update() 호출

	// 5. (3) 에서 생성된 객체를 반환.. 
	//    => 즉, 여기서 main 으로 반환




	//---------------------------------------------
	std::cout << "foo 1" << std::endl;

	co_await std::suspend_always{};

	std::cout << "foo 2" << std::endl;
}



int main()
{
	foo();
}
