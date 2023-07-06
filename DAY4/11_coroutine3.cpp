#include <iostream>
#include <coroutine>

// Generator 에 "promise_type" 이 없을때 에러
// => 'promise_type': 'std::coroutine_traits<Generator>'의 멤버가 아닙니다.

// Generator 에 "promise_type" 이 있을때 에러메세지가 변경됩니다.

// Step 3. 코루틴의 규칙
// => 반드시 "promise_type" 이라는 멤버 타입이 있는 타입을 반환해야 한다.

// 결론 : 코루틴의 반환 타입은
// => 사용자 정의 타입(클래스)로 설계하고
// => "promise_type" 이라는 타입을 멤버로 넣으세요.


class Generator
{
public:
	using promise_type = int;
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
