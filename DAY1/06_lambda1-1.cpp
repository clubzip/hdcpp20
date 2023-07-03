#include <iostream>

// C++20 에서 람다 표현식이 더욱 발전 됩니다.

int main()
{
	// generic lambda 를 사용한 swap
	auto swap1 = [](auto& a, auto& b) { auto t = a; a = b; b = t; };

	int n = 10;
	double d = 3.4;

	// 아래 코드는 되는게 좋을까요 ? 에러가 좋을까요 ?
	swap1(n, d); // 에러 아님..
				 // generic lambda 는 2개의 인자가 서로 다른 템플릿!
	

	// 위 문제를 해결하기 위해서 C++20 부터는 람다표현식도 템플릿 가능합니다.
	auto swap2 = []<typename T>(T& a, T& b) { auto t = a; a = b; b = t; };

	swap2(n, d); // error. 2개의 인자는 반드시 같은 타입이어야 합니다.

	// 템플릿 인자 여러개 해도됩니다.
	auto add1 = []<typename T1, typename T2>(T1 a, T2) { return a + b; };
	auto add2 = [](auto a, auto b) { return a + b; }; // 위와 동일
}

// C++11 : 람다 표현식 도입
// C++14 : generic 람다 표현식 등장
// C++20 : template 람다 표현식 등장