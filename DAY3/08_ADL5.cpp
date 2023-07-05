#include <iostream>
#include <ranges>
#include <vector>
#include <algorithm>

int main()
{
	std::vector v = { 1,2,3,4,5 };

	// C++98 알고리즘 : 모두 함수(템플릿) 입니다.
	auto ret1 = std::find(v.begin(), v.end(), 3);

	// C++20 알고리즘 : 모두 함수객체 입니다.
	auto ret2 = std::ranges::find(v, 3);
	auto ret3 = std::ranges::find.operator()(v, 3);
}