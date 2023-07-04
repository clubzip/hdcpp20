#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>
#include <iostream>
#include <type_traits>

// C++ ������ advance ����
// => empty class �� �߻�ȭ�� ������ Ÿ��ȭ �ϰ�
// C++98 : �ݺ��� �����ڰ� �ڽ��� � �������� �˷��ְ�, tag dispatching
// C++17 : �ݺ��� �����ڰ� �ڽ��� � �������� �˷��ְ�, if constexpr

// C++17 ������ ���� : �ݺ��� �����ڰ� "��ӵ� iterator_category" ��
//				�ڽ��� ������ �˷� �־�� �մϴ�.
// => ���� raw pointer(int*) ��� iterator_category ��� ������ Ÿ����
//    ������ �����ϴ�. (iterator_traits ���� ����� �ذ��ؾ� �մϴ�.)

// C++20 
// => �Է¹ݺ���, ����� �ݺ���, �������� �ݺ��ڵ��� �߻�ȭ�� ������
// => concept ���� ���� �մϴ�
// => if ������ �����ص� �ǰ�, require clauses(�����ð�)���� Ȱ���ص� �˴ϴ�.

// �ݺ��� �����ڰ� �˷��� �ʿ� �����ϴ�.

template<typename T>
void xadvance(T& p, int n)
{
	// ���� Ÿ���� "Ư�� ����"�� �����ϸ� ���� ����ȭ�� ������ �����մϴ�.
	// => ������ �����ϴ� ���� ���� ����� "������ �ð�"�� �̷�� ���ϴ�.
	if constexpr ( std::random_access_iterator<T> )
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
