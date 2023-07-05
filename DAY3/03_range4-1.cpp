#include <vector>
#include <iostream>

// 핵심 1. 아래 헤더에 take_view, reverse_view 같은 view 가 30여개 제공됩니다.
#include <ranges>

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	// 핵심 2. 다양한 view 클래스는 3가지 방법으로 생성 할수 있습니다.
	// => namespace 이름 꼭 기억해 두세요

	// 방법 1. 클래스 이름 직접 사용
	std::ranges::take_view tv1(v, 5);


	// 방법 2. 생성 함수 사용
	auto tv2 = std::views::take(v, 5);


	// 방법 3. pipe line 사용
	auto tv3 = v | std::views::take(5);





	for (auto e : v)
		std::cout << e << ", ";

	std::cout << std::endl;



}