#include <iostream>
#include <vector>
#include <list>
#include <iterator>

template<typename T> 
void iter_type(T first)
{
	// T 가 반복자일때 T가 가리키는 요소의 타입을 얻은 방법
	
	// 방법 1. auto 사용 - 반드시 우변 필요!
	auto s1 = *first; 

	// 방법 2. C++98 스타일
	typename T::value_type s2; // T 가 포인터 라면 에러
	typename std::iterator_traits<T>::value_type s3; // T 가 포인터		
										// 라도 ok

	// 방법 3. C++20 스타일
	std::iter_value_t<T> s4;
}



int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
}










