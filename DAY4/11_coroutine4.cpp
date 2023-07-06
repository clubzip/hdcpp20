#include <iostream>
#include <coroutine>


// Step 4. promise_type 의 조건
// => 사용자 정의 클래스로 설계 하고
// => 약속된 5개의 함수를 만들고. 
// => Generator 안에서 "promise_type" 이라는 이름으로 노출


class Generator
{
public:
	// promise 멤버 함수 안에서 Generator 클래스 이름을 사용하게 됩니다.
	// => 그래서 보통 nested 로 설계 합니다.
	// => 반드시 nested 로 해야 하는 것은 아닙니다
	// => 전방선언등으로 해결해도 됩니다.
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
	std::cout << "foo 1" << std::endl;

	co_await std::suspend_always{};

	std::cout << "foo 2" << std::endl;
}


int main()
{
	foo();
}
