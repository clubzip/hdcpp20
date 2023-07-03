#include <iostream>

// C++20 에서 람다 표현식이 더욱 발전 됩니다.

int main()
{
	// generic lambda 를 사용한 swap
	auto swap1 = [](auto& a, auto& b) { auto t = a; a = b; b = t; };

	int n = 10;
	double d = 3.4;

	// 아래 코드는 되는게 좋을까요 ? 에러가 좋을까요 ?
	swap1(n, d);
}

