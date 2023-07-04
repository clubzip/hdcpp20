#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>
#include <iostream>
#include <type_traits>

// C++ 버전별 advance 구현
// C++98 : 반복자 설계자가 자신이 어떤 종류인지 알려주고, tag dispatching
// C++17 : 반복자 설계자가 자신이 어떤 종류인지 알려주고, if constexpr


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
