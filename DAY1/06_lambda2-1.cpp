#include <iostream>

int foo() { return 0; }

int main()
{
	// ���� : �򰡵��� ���� ǥ����(unevaluated expression)
	int n2 = sizeof( foo() );



	// 1. C++20 ������ ����ǥ������ �򰡵��� ���� ǥ���Ŀ� ������ �������ϴ�.
	int n = sizeof( [](int a, int b) { return a + b; } );

	decltype( [](int a, int b) { return a + b; } ) f;
}