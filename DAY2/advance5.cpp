#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>
#include <iostream>
#include <type_traits>

// C++ ������ advance ����
// C++98 : �ݺ��� �����ڰ� �ڽ��� � �������� �˷��ְ�, tag dispatching
// C++17 : �ݺ��� �����ڰ� �ڽ��� � �������� �˷��ְ�, if constexpr


template<typename T>
void xadvance(T& p, int n) 
{
	if constexpr ( std::is_same_v< typename T::iterator_category,
		                 std::random_access_iterator_tag> )
		p = p + n;
	else
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
