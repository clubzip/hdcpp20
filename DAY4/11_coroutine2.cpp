#include <iostream>
#include <coroutine>

// Step 2. 함수를 coroutine 으로 만들려면
// 
// => 함수 안에서 "co_wait", "co_yield", "co_return" 중 한개의 키워드를
//    사용하면 coroutine 이 됩니다

void foo()
{
	std::cout << "foo 1" << std::endl;

	co_wait std::suspend_always{};

	std::cout << "foo 2" << std::endl;
}


int main()
{
	foo();
}
