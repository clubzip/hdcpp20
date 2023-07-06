#include <functional>
#include <iostream>
using namespace std::placeholders;

void foo(int a, int b)
{
	std::cout << a << ", " << b << std::endl;
}

int main()
{
	// C++11 bind
	// => 기존 함수의 인자를 특정한 값으로 고정한 새로운 함수를 만드는 도구
	
	// 인자가 2개인 함수(foo) 의 1번째 인자를 고정한 새로운 함수를 만드는 코드
	auto f1 = std::bind(&foo, 0, _1);
	f1(20); // foo(0, 20) 으로 호출..


	// C++20 bind_front : 1번재 인자를 고정한 함수 만들기.

}
