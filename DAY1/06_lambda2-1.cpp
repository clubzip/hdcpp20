#include <iostream>

int main()
{
	// 1. C++20 전에는 람다표현식은 평가되지 않은 표현식에 넣을수 없었습니다.
	int n = sizeof( [](int a, int b) { return a + b; } );

	decltype([](int a, int b) { return a + b; }) f;
}