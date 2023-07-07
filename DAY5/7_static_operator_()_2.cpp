#include <iostream>

class less
{
public:
	bool operator()(int a, int b)
	{
		return a < b;
	}

	using F = bool(*)(int, int);

	// �Ʒ� �Լ��� "��ȯ������" ��� �Լ� �Դϴ�. 
//	operator F() { return �Լ��ּ�; }

	operator F() { return &less::operator(); }
};



int main()
{
	less f;

	// �ᱹ f �� ���� �Լ� �Դϴ�.
	// �Ʒ� ó�� ����Ҽ� ������� ?
	// (�Լ� �����Ͱ� �ʿ��� ���� f�� ������ ������??)
	bool(*p)(int, int) = f;
			// => f �ȿ� ��ȯ ������ �� �߰��ϸ� �˴ϴ�.
			// => f.operator �Լ�������Ÿ��()
}