#include <iostream>
#include <vector>
#include <list>
#include <iterator>

// 반복자가 가리키는 타입 얻기
// C++98 : typename std::iterator_traits<T>::value_type
// C++20 : std::iter_value_t<T>     <= typename 필요 없음


template<typename T>
std::iter_value_t<T> sum(T first, T last)
{
	std::iter_value_t<T> s = 0;

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
	int v[10] = { 1,2,3,4,5,6,7,8,9,10 };

	int s = sum(std::begin(v), std::end(v)); 

	std::cout << s << std::endl; // 55
}










