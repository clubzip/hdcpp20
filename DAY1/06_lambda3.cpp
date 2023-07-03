#include <iostream>

class Sample
{
	int value;
public:
	void foo()
	{
		// ����ǥ���Ŀ��� ��� ����Ÿ ����ϱ�.

		// 1. this �� ĸ���ϸ� ��� ����Ÿ�� ���� �����մϴ� - C++11
		auto f1 = [this](int a) { return a + value; }; // ?

		// 2. this ��� = �� ĸ���ص� �������Ÿ ���� �����մϴ�.
		// = ĸ�� : ��� ���������� ĸ�� �ϰڴٴ� �ǹ�
		auto f2 = [=](int a) { return a + value; }; // ?
				// C++17 ������ ����.
				// C++20 ���ʹ� ������ �Ǿ����ϴ�.
				// �����Ϸ��� ����, ���� �Ǵ� ��� �߻�

		f2(0);

		// ��� : ����ǥ���Ŀ��� ��� ����Ÿ ���� �Ϸ���
		// ������ [=] ���� ����
		// [this] �θ� �ϼ���..
	}
};


int main()
{
	Sample s;
	s.foo();
}