// fo5
#include <iostream>

// �Լ���ü�� ������ �˾Ҵٸ�!!
// �Լ���ü�� ����� ����� ���ô�.

struct plus
{
	inline int operator()(int a, int b) const
	{
		return a + b;
	}
};

int main()
{
	plus p;

	int n = p(1, 2);
}