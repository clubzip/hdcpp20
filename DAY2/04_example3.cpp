#include <iostream>
#include <algorithm>
#include <concepts>
#include <vector>
#include <list>

template<typename T> requires std::random_access_iterator<T>
void mysort(T first, T last)
{
	std::cout << "quick sort" << std::endl;
}

template<typename T> requires std::bidirectional_iterator<T>
void mysort(T first, T last)
{
	std::cout << "bubble sort" << std::endl;
}

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	std::list<int>   s = { 1,2,3,4,5,6,7,8,9,10 };

	// STL 의 std::sort 는 퀵소트 입니다. - 임의 접근 반복자만 전달 가능
	std::sort(v.begin(), v.end()); // ok
//	std::sort(s.begin(), s.end()); // error

	s.sort();	// ok. list 를 sort 할때는 멤버 함수 사용하면 됩니다.
				// 퀵 소트가 아닌 다른 알고리즘(bubble, selection 등)

	mysort(s.begin(), s.end());
	mysort(v.begin(), v.end());

	// 핵심 : vector 의 반복자는
	//       std::random_access_iterator 와 std::bidirectional_iterator
	//	     를 모두 만족합니다.
	//	     => 하지만 에러는 아닙니다.
	//		 => random_access_iterator concept = bidirectional_iterator + 추가조건
	//		 => 이므로 random_access_iterator 버전 사용.
}