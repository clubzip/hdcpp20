#include <iostream>
#include <functional>

// �Լ� ��ü ( function object )
// => () �����ڸ� �������ؼ� �Լ� ó�� ��� ������ ��ü
// => �Ϲ� �Լ����� �������� ������ �ִ�.

struct plus
{
	int operator()(int a, int b) const
	{
		return a + b;
	}
};

int main()
{
	plus p;

	int n = p(1, 2); // p.operator()(1,2)
}