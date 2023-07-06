#include <iostream>

// variable template 문법 - C++14 도입

constexpr int variable = 0;		// 일반 전역변수(상수)

template<typename T>
constexpr int made_year = 0;	// 템플릿으로 만든 전역변수
								// "variable template"
class Date
{
};
// 이제, variable template 인 made_year 를 "Date" 타입에 대해서 특수화 합니다.
template<>
constexpr int made_year<Date> = 2023;

int main()
{
	std::cout << variable  << std::endl; // ok
//	std::cout << made_year << std::endl; // error. template 인데, 인자가 없으므로

	std::cout << made_year<int>   << std::endl; // ok. 0
	std::cout << made_year<float> << std::endl; // ok. 0
	std::cout << made_year<Date> << std::endl;  // 2023
}



