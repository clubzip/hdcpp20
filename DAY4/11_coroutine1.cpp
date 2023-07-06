#include <iostream>

// subroutine : 일반 함수의 호출,  call, return 개념
// coroutine  : call, return 외에, suspend, resume, destroy 개념이 존재

// coroutine 의 핵심 : 지역변수를 보관하는 stack 을 어떻게 관리할것인가 ?
// coroutine 의 2가지 종류

// 1. stackful coroutine : 지역변수를 stack 에 보관하는 방식
// 2. stackless coroutine : 지역변수를 stack 이 아닌
//							힙등에 보관.

// C++은 "stackless" 입니다.
// => coroutine 의 지역변수는 힙에 놓이게 됩니다.


// C#, Python, java, Go 등의 언어
// => coroutine 만들기 쉽습니다.
// => return 대신 yield 만하면 됩니다.

// C++ coroutine
// => 상당히 복잡합니다.
// => C++20 에서 Framework 만 만들고,, 
//    라이브러리 지원은 C++23 으로 미루게 되었습니다.


// Step 1. 일반 함수
void foo()
{
	std::cout << "foo 1" << std::endl;
	std::cout << "foo 2" << std::endl;
}

int main()
{
	foo();
}
