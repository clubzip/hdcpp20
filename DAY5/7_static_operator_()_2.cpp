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

	//operator F() { return &less::operator(); }
				// => error
				// => F �� �Ϲ��Լ� ������ Ÿ���ε�..
				// => &less::operator() �� ��� �Լ��� �ּ�.
	
	// �ذ�å 
	// 1. operator() �� static ��� �Լ��� �ϸ� �˴ϴ�.
	//		=> C++23 ���� �����մϴ�.
	//		=> C++23 �������� operator() �� static �� �ɼ� �����ϴ�.

	// 2. C++23 ������ �ذ�å
	//		=> operator() �� ������ ���� �ϴ� "static ��� �Լ��� ������ �ۼ�"

	static bool helper(int a, int b)
	{
		return a < b;
	}
	operator F() { return &less::helper; }
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