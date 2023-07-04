#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>
#include <iostream>
#include <type_traits>

// 타입의 조건에 따라 template 을 다르게 구현하는 방법

// 1. if constexpr 사용
/*
template<typename T>
void xadvance(T& p, int n)
{
	if constexpr (std::random_access_iterator<T>)
		p = p + n;
	else
		while (n--)
			++p;
}
*/
// 2. require clauses 사용해서 동일 이름의 서로 다른 템플릿 제공

template<typename T> requires std::random_access_iterator<T>
void xadvance(T& p, int n)
{
	p = p + n;
}

template<typename T> requires (!std::random_access_iterator<T>)
void xadvance(T& p, int n)
{
	while (n--)
		++p;
}


int main()
{
	std::list<int>   c = { 1,2,3,4, 5, 6, 7 };
	//	std::vector<int> c = { 1,2,3,4, 5, 6, 7 };

	auto p = c.begin();

	xadvance(p, 5);

	std::cout << *p << std::endl; // 6
}
