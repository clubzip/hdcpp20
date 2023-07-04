#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>
#include <iostream>
#include <type_traits>

// Ÿ���� ���ǿ� ���� template �� �ٸ��� �����ϴ� ���

// 1. if constexpr ���
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
// 2. require clauses ����ؼ� ���� �̸��� ���� �ٸ� ���ø� ����

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
