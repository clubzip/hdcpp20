// advance1
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>
#include <iostream>

/*
// 핵심 1. 5개의 분류가 추상적인 개념인데, 
//  => 이것을 empty class 로  타입화 합니다.

struct input_iterator_tag {};
struct ouput_iterator_tag {};
struct forward_iterator_tag : input_iterator_tag {};
struct bidirectional_iterator_tag : forward_iterator_tag {};
struct random_access_iterator_tag : bidirectional_iterator_tag {};


// 핵심 2. 이제 각 반복자를 만들때 자신이 어떤 종류(category)인지
//        알려 주기로 했습니다
template<typename T> class vector_iterator
{
public:
	typedef random_access_iterator_tag iterator_category;
};

template<typename T> class list_iterator
{
public:
	typedef bidirectional_iterator_tag iterator_category;
};
*/
// 핵심 3. 이제 위 5개 타입을 사용해서 xadvance를 overloading합니다.
// => "tag dispatching" 이라 불리는 기술입니다.
template<typename T>
void xadvance_imp(T& p, int n, std::random_access_iterator_tag a)
{
	p = p + n;
}
template<typename T>
void xadvance_imp(T& p, int n, std::input_iterator_tag a)
{
	while (n--) ++p;
}
// C++ 표준의 advance 를 만들어 봅시다. - C++98
template<typename T>
void xadvance(T& p, int n) // n > 0 만 고려 합니다
{
	// T가 어떤 종류의 반복자인지에 따라 함수 오버로딩을 하게 합니다.
	xadvance_imp(p, n, typename T::iterator_category());

}


int main()
{
	std::list<int>   c = { 1,2,3,4, 5, 6, 7 };
	//	std::vector<int> c = { 1,2,3,4, 5, 6, 7 };

	auto p = c.begin();

	xadvance(p, 5);

	std::cout << *p << std::endl; // 6
}
