#include <iostream>
#include <cmath>
#include <compare> // std::strong_odering 

// <=> 연산자의 반환 타입
// 1. std::strong_ordering : 두개의 요소가 "같음"을 비교할때 나오는 타입
// 2. std::weak_ordering   : 두개의 요소가 "대등함"을 비교할때 나오는 타입
// 3. std::partial_ordering : 두개의 요소비교 할수도 있지만, 비교될수 없을때도 있을때

int main()
{
	// 핵심 1. 정수를 <=> 연산하면 std::strong_ordering 가 반환 됩니다.
	auto ret1 = (3 <=> 4);

	// 아래 2줄은 동일한 의미.
	if (ret1 > 0) {}
	if (ret1 == std::strong_ordering::greater) {}

}