#include <iostream>

template<typename ... ARGS> void foo(int a1, ARGS&& ... args)
{
	int v1 = 10, v2 = 10;

	// ���� ǥ���Ŀ��� �� �������� ĸ��.
	// 1. ���� ǥ���Ŀ��� ���������� ����Ϸ��� ĸ�� �ϸ� �˴ϴ�. - C++11
	auto f1 = [ v1, v2 ](int x) { return x + v1 + v2; };
	
	// 2. �Լ� ���ڵ� �ᱹ �������� �Դϴ�. ĸ�� �����մϴ�. - C++11
	auto f2 = [ v1, a1 ](int x) { return x + v1 + a1; };
	
	// 3. C++20 ����. �������� ���ø��� "�Ķ���� ��"�� ĸ�� �����մϴ�.
	auto f3 = [ ...arg = std::forward<ARGS>(args) ](int a)
	{
		(std::cout << ... << args); // C++17 fold expression
	};
	f3(10);
}

int main()
{
	int a1 = 1, a2 = 2, a3 = 3;
	foo(0, a1, a2, a3);
}