#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

// 지연된 실행

int main()
{
	std::vector v = { 1,2,3,4,5,6,7,8,9,10 };

	// fv 는 내부적으로
	// => v를 참조로 보관하고, filter 로 전달한 함수를 보관만 합니다.
	// => 실제 함수가 적용되는 시점은 "열거" 할때 입니다.
	// => 즉, fv 자체가 요소를 보관하는 것은 아닙니다.
	auto fv = v | std::views::filter([](int n) { return n % 2 == 0; });
	
//	std::ranges::filter_view fv(v, [](int n) { return n % 2 == 0; });

	// fv 를 생성한 후에 v 를 변경
	v[1] = 20;
	v[3] = 40;
	v[5] = 60;

	// v 변경된 값에 fv 에 가진 filter 적용
	for (auto e : fv) //  20, 40, 60, 8, 10
	{
		std::cout << e << ",  ";
	}
	std::cout << std::endl;
}
// C# 도 위와 동일한 기술이 있습니다. 
// LINQ 라고 합니다 Language INtegrated Query
// C++ : v | filter( 함수 )
// C#  : v.select( 함수 ).order(조건) 처럼 쿼리 문 같이 사용

