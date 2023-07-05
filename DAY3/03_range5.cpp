#include <vector>
#include <iostream>
#include <ranges>

// nested..

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	// 핵심 1. 중첩 가능합니다. !!! 중요!!!

	// 방법 1. 클래스 이름 직접 사용
	std::ranges::take_view tv(v, 5);
	std::ranges::filter_view fv(tv, [](int n) { return n % 2 == 0; });
	std::ranges::reverse_view rv(fv);




	// 방법 2. 함수 버전
	auto rv2 = std::views::reverse(std::views::filter(
							std::views::take(v, 5),
								[](int n) { return n % 2 == 0; }));

	// 방법 3. pipe line 라인 
	// => 주의 reverse_view 의 pipe line 버전은 함수가 아닌 std::views::reverse
	auto rv3 = v | std::views::take(5)
				 | std::views::filter([](int n) { return n % 2 == 0; })
				 | std::views::reverse;
	
//	for (auto e : rv2)  // 4, 2
	for (auto e : v | std::views::take(5) | std::views::reverse ) 
	{
		std::cout << e << ", ";
	}
	std::cout << std::endl;
}