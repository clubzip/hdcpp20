// advance1
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>
#include <iostream>

int main()
{
	std::list<int>   c = { 1,2,3,4, 5, 6, 7 };
//	std::vector<int> c = { 1,2,3,4, 5, 6, 7 };

	auto p = c.begin(); 

	// p를 5칸 전진하려고 합니다.
	// => 최선의 선택은 ??
//	p = p + 5; // 가장 빠르지만, 임의접근 반복자(vector 반복자)만 가능

//	++p; ++p; ++p; ++p; ++p; // 모든 반복자에 사용가능하지만
							 // 임의접근 반복자라면 느립니다.

	// 최선의 코드는 아래 방법 입니다.
	std::advance(p, 5);

	std::cout << *p << std::endl; // 6
	

}
