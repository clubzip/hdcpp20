#include <iostream>
#include <type_traits>
#include <vector>


// traits : Ÿ�Կ� ���� Ư���� �����ϴ� ���, 
//          template �κ� Ư��ȭ �������� �����.
//			"is_xxx" ó�� ���� ���

// concept : Ÿ�Կ� ���� ����(������ ǥ��), C++20
//			concept ���� ���
//			"is_" �� ������� ����� ����

template<typename T>
concept container = requires(T c)
{
	// ���� ��� 1. begin(), end() ��� �Լ��� �־�� �Ѵ�.
	c.begin();
	c.end();
};
template<typename T> void check(T& c)
{
	// concept�̸�<Ÿ��> �ϸ� �����ϴ��� ���� �����մϴ�.
	bool b = container<T>;
	std::cout << b << std::endl;
}

int main()
{
	int n = 0;
	std::vector<int> v = { 1,2,3 };
	int x[3] = { 1,2,3 };

	check(n); // false
	check(v); // true
	check(x); // ?
}