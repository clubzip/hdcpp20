#include <iostream>

// C++ ���������� "�Լ� ��ü" �� ���� �θ� ����մϴ�.
// => C++20 ���� �߰��� ��� �˰����� "�Լ�" �� �ƴ� "�Լ� ��ü" �Դϴ�.

// �Լ� ��ü : () �����ڸ� �������ؼ� �Լ� ó�� ��밡���Ѱ�!

class less
{
public:
	bool operator()(int a, int b) 
	{
		return a < b;
	}
};
int main()
{
	less f;
	bool b1 = f(1, 2);
	bool b2 = f.operator()(1, 2); // ���� �̷��� ����ص� �˴ϴ�.
}