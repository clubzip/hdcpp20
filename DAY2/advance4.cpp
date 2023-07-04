// advance1
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>
#include <iostream>

/*
// �ٽ� 1. 5���� �з��� �߻����� �����ε�, 
//  => �̰��� empty class ��  Ÿ��ȭ �մϴ�.

struct input_iterator_tag {};
struct ouput_iterator_tag {};
struct forward_iterator_tag : input_iterator_tag {};
struct bidirectional_iterator_tag : forward_iterator_tag {};
struct random_access_iterator_tag : bidirectional_iterator_tag {};


// �ٽ� 2. ���� �� �ݺ��ڸ� ���鶧 �ڽ��� � ����(category)����
//        �˷� �ֱ�� �߽��ϴ�
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
// �ٽ� 3. ���� �� 5�� Ÿ���� ����ؼ� xadvance�� overloading�մϴ�.
// => "tag dispatching" �̶� �Ҹ��� ����Դϴ�.
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
// C++ ǥ���� advance �� ����� ���ô�. - C++98
template<typename T>
void xadvance(T& p, int n) // n > 0 �� ��� �մϴ�
{
	// T�� � ������ �ݺ��������� ���� �Լ� �����ε��� �ϰ� �մϴ�.
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
