#include <iostream>
#include <vector>

// C++20 의 ranges 라이브러리 안에는
#include <ranges>

int main()
{
	std::vector v = { 1,2,3,4,5 };

	// 1. 다양한 view 가 있습니다. 흔히 "range adaptor" 라고 부릅니다.
	std::ranges::take_view tv(v, 5);


	// 2. range 의 다양한 특성을 조사하는 concept 도 있습니다.
	bool b1 = std::ranges::range<std::vector<int>>; // true
	bool b2 = std::ranges::borrowed_range<std::vector<int>>; // false
	

	// 3. 다양한 함수도 있습니다.
	auto p1 = std::ranges::size(tv);


	// 4. 다양한 타입 유틸리티도 있습니다.
	std::ranges::range_value_t< std::vector<int>> n; // int
}