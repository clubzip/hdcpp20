#include <iostream>

// C++20 ���� ���� ǥ������ ���� ���� �˴ϴ�.

int main()
{
	// generic lambda �� ����� swap
	auto swap1 = [](auto& a, auto& b) { auto t = a; a = b; b = t; };

	int n = 10;
	double d = 3.4;

	// �Ʒ� �ڵ�� �Ǵ°� ������� ? ������ ������� ?
	swap1(n, d); // ���� �ƴ�..
				 // generic lambda �� 2���� ���ڰ� ���� �ٸ� ���ø�!
	
	// �� ������ �ذ��ϱ� ���ؼ� C++20 ���ʹ� ����ǥ���ĵ� ���ø� �����մϴ�.
	auto swap2 = []<typename T>(T & a, T & b) { auto t = a; a = b; b = t; };

	swap2(n, d); // error. 2���� ���ڴ� �ݵ�� ���� Ÿ���̾�� �մϴ�.
}

