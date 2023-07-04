#include <iostream>
#include <vector>
#include <list>
#include <iterator>

// 구간의 합을 구하는 sum 을 만들어 봅시다.

// T 가 반복자 일때
// 1. 반복자가 가리키는 타입은 "T::value_type" 으로 표기 - C++98

// 2. T::value_type => 컴파일러가 value_type 을 타입이 아닌 값으로 해석
//						(static member data 등으로 해석)
//    typename T::value_type => 이렇게 해야 타입으로 해석됩니다.

// 이 소스의 핵심 : "typename T::value_type" 표기법 알아 두세요 - C++98

template<typename T>
typename T::value_type sum(T first, T last)
{
	typename T::value_type s = 0;

//	auto s = *first;

	while (first != last)
	{
		s += *first;
		++first;
	}
	return s;
}


int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	int s = sum(v.begin(), v.end());

	std::cout << s << std::endl; // 55
}










