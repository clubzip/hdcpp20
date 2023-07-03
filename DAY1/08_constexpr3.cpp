#include <iostream>
#include <algorithm>
#include <numeric>
#include <array>

// STL 의 많은 알고리즘 과 "constexpr"
// => 아주 많은 STL 알고리즘이 "컴파일 시간에 사용가능" 해졌습니다.

int main()
{
//	constexpr int c = exp; // exp 의 결과는 "반드시 컴파일 시간에 알아야 한다"는 것

	constexpr int x[10] = { 1,2,3,4,5,6,7,8,9,10 };

	constexpr int c = std::accumulate(std::begin(x), std::end(x), 0);
				

	// 단, find 는 컴파일 시간 지원 안됩니다
	constexpr auto p = std::find(std::begin(x), std::end(x), 5); // error
}
