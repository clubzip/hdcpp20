#include <iostream>
#include <cmath>
#include <compare> // std::strong_odering 

// <=> 연산자의 반환 타입
// ==> 0 보다 크거가, 같거나, 작다.
// 1. std::strong_ordering : 두개의 요소가 "같음"을 비교할때 나오는 타입
// 2. std::weak_ordering   : 두개의 요소가 "대등함"을 비교할때 나오는 타입
// 3. std::partial_ordering : 두개의 요소비교 할수도 있지만, 비교될수 없을때도 있을때

int main()
{
	// 핵심 1. 정수를 <=> 연산하면 std::strong_ordering 가 반환 됩니다.
	// => 0 보다 크거가, 같거나, 작다.
	auto ret1 = (3 <=> 4);

	// 아래 2줄은 동일한 의미.
	if (ret1 > 0) {}
	if (ret1 == std::strong_ordering::greater) {}


	// 핵심 2. 실수는 "NAN(Not An Number)" 라는 개념이 있습니다.
	// "sqrt(음수)" 의 결과는 NAN 입니다.
	// => 그래서 <=> 의 결과는 
	// => 0보다, 크거나, 같거나, 작거나, 비교 할수 없음 입니다.
	// => 반환 타입은 std::partial_odering 입니다.

	auto ret2 = 1.2 <=> 3.4;		   // 실수 <=> 실수
	auto ret3 = 1.2 <=> std::sqrt(-2); // 실수 <=> NaN
	
	if (ret2 < 0) {}
	if (ret3 == std::partial_ordering::unordered ) 
	{
		std::cout << "비교할수 없음" << std::endl;
	}
}