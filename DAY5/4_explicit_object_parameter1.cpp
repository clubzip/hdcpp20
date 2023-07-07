#include <iostream>

// C++23 �� Big 1 : Explicit Object Parameter
// => ���� �������� "Deducing this" ��� �θ��ϴ�.

class Sample
{
	int x, y;
public:
	// �Ʒ� �Լ��� �ᱹ	       �����Ϸ��� ���� �Ʒ�ó�� ����˴ϴ�
	void f1(int a, int b)	// void f1(Sample* this, int a, int b)
	{
		std::cout << "f1" << std::endl;
	}

	// C++23 ���� ��ü�� ��������� �޴� ������ ���Ե˴ϴ�.
	// => �Ʒ� �ڵ忡�� "self" �� ���� �̸��Դϴ�. �ƹ��̸��̳� ��������ϴ�.
	// => Python �� ������ �����Դϴ�.
	void f2(this Sample& self, int a, int b)
	{
//		x = a; // error
		self.x = a; // ok
		self.y = b;

		std::cout << "f2" << std::endl;
	}
};

int main()
{
	Sample s;
	s.f1(1, 2);	// f1(&s, 1, 2)
	s.f2(1, 2); // f2(s, 1, 2)
}