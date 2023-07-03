#include <iostream>

// C++20 에서 람다 표현식이 더욱 발전 됩니다.

int main()
{
	// add1 : int 타입 2개를 받는 람다 표현식
	auto add1 = [](int a, int b) { return a + b; };

	std::cout << add1(1, 2)     << std::endl;
	std::cout << add1(3.4, 4.2) << std::endl; // 에러는 아니지만 결과가 7


	// C++14의 generic lambda : 람다 표현식 인자로 auto 사용가능
	auto add2 = [](auto a, auto b) { return a + b; };

	std::cout << add2(1, 2)     << std::endl; // 3
	std::cout << add2(3.4, 4.2) << std::endl; // 7.6
	std::cout << add2(3,   4.2) << std::endl; // 7.2
	std::cout << add2(3.4, 4)   << std::endl; // 7.4
}
// C++14 generic lambda 의 원리
// => 핵심 2개의 인자가 서로 다른 템플릿
class CompilerGeneratedName
{
public:
	template<typename T1, typename T2>
	auto operator()(T1 a, T2 b) const
	{
		return a + b;
	}
};
