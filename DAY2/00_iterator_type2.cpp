#include <iostream>
#include <vector>
#include <list>
#include <iterator>

template<typename T>
typename T::value_type sum(T first, T last)
{
	typename T::value_type s = 0;

	while (first != last)
	{
		s += *first;
		++first;
	}
	return s;
}


int main()
{
//	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
//	std::list<int>   v = { 1,2,3,4,5,6,7,8,9,10 };

	// raw array 도 결국은 컨테이너(여러개의 값을 보관) 입니다.
	int v[10] = { 1,2,3,4,5,6,7,8,9,10 };

//	int s = sum(v.begin(), v.end()); // 멤버 함수 begin() 사용
									 // => raw array 인 경우 에러

	int s = sum(std::begin(v), std::end(v)); // 일반 함수 begin
											 // => raw array 도가능
											 // => C++11 에서 도입

	std::cout << s << std::endl; // 55
}










