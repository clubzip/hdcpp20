#include <iostream>
#include <algorithm>
#include <vector>
#include <ranges>

int main()
{
	std::vector v = { 1,2,3,4,5 };
//	int v[] = { 1,2,3,4,5 };

	// 반복자를 얻는 방법
	// 1. C++98
	// => 단점 : v 가 raw array 인 경우는 에러!
	auto p1 = v.begin();		


	// 2. C++11 : 멤버가 아닌 일반함수 begin 도입
	// => v 가 raw array 라도 ok.
	auto p2 = std::begin(v);	

	auto sz1 = v.size();     // v 가 raw array 라면 에러
	auto sz2 = std::size(v); // v 가 raw array 라도 ok. 
	


	// 3. C++20 에서 "새로운 begin()" 이 추가되었습니다.
	// std::ranges : namespace 이름. std 안에 ranges 라는 이름 공간
	// namespace std
	// {
	//		namespace ranges {    }
	// }
	auto p3 = std::ranges::begin(v);
}