#include <iostream>
#include <coroutine>

// Step 2. 함수를 coroutine 으로 만들려면
// 
// => 함수 안에서 "co_await", "co_yield", "co_return" 중 한개의 키워드를
//    사용하면 coroutine 이 됩니다

// 아래 코드는 에러 입니다.
// => coroutine 이 지켜야 하는 규칙이 있는데.
// => 규칙을 지키지 않았습니다.

void foo()
{
	std::cout << "foo 1" << std::endl;

	co_await std::suspend_always{};

	std::cout << "foo 2" << std::endl;
}


int main()
{
	foo();
}
