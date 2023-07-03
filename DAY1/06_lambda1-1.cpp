#include <iostream>

// C++20 ���� ���� ǥ������ ���� ���� �˴ϴ�.

int main()
{
	// generic lambda �� ����� swap
	auto swap1 = [](auto& a, auto& b) { auto t = a; a = b; b = t; };

	int n = 10;
	double d = 3.4;

	// �Ʒ� �ڵ�� �Ǵ°� ������� ? ������ ������� ?
	swap1(n, d);
}

