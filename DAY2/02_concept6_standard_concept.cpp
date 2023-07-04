#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <concepts>
#include <iterator>
#include <ranges>  

template<typename T>
void check(T arg)
{
	// 아래 있는 input_iterator, bidirectional_iterator, random_iterator
	// 가 모두 미리 정의되어 있는 concept 입니다.
	// 이처럼 수십개의 concept 이 미리 정의되어 있습니다.
	std::cout << std::input_iterator<T> << std::endl;
	std::cout << std::bidirectional_iterator<T> << std::endl;
	std::cout << std::random_access_iterator<T> << std::endl;
}

int main()
{
	std::cout << std::boolalpha;

	std::vector<int> v = { 1,2,3 };
			// vector 반복자 : ++, -- 뿐 아니라 +, - 도 가능합니다.
			//				 random access iterator 라고 합니다.
	
	std::list<int>   s = { 1,2,3 };
			// list 반복자 : +, - 는 안되고, ++, -- 만 가능합니다.
			//				bidirectional iterator 라고 합니다.

	int x[3] = { 1,2,3 };

	check(std::begin(v));
	check(std::begin(s));
	check(std::begin(x));

}