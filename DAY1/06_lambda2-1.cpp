#include <iostream>

int main()
{
	// 1. C++20 ������ ����ǥ������ �򰡵��� ���� ǥ���Ŀ� ������ �������ϴ�.
	int n = sizeof( [](int a, int b) { return a + b; } );

	decltype([](int a, int b) { return a + b; }) f;
}