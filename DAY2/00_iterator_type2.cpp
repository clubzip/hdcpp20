#include <iostream>
#include <vector>
#include <list>
#include <iterator>

// std::begin(v) 에서
// 1. v 가 STL container 이면 : T 는 객체형 반복자( class 로 설계된)
// 2. v 가 raw array 이면     : T 는 raw pointer( int* )

// 반복자의 2가지 종류
// 1. class 로 만들어진 반복자 ( vector 나 list 반복자 )
// 2. raw pointer => C++에서 raw pointer 도 반복자의 종류입니다.

// 반복자의 종류가 위 2가지가 있기때문에 아래 sum 같은 함수 만들기가
// 어렵습니다.
// 이 문제를 해결하는 도구가 "iterator_traits" 입니다.

template<typename T> struct iterator_traits
{
	using value_type = typename T::value_type;
};

// T 가 "raw pointer" 인 경우에는 구현을 다르게 하기 위해
// 부분 특수화 문법 사용
template<typename T> struct iterator_traits<T*>
{
	using value_type = T;
};

template<typename T>
typename iterator_traits<T>::value_type sum(T first, T last)
{
//	typename T::value_type s = 0;

	typename iterator_traits<T>::value_type s = 0;


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










