#include <iostream>

class Sample
{
public:
	// �ٽ� : �����̸��� �Լ��� const, non-const �� ���ÿ� 
	//       ����� �ֽ��ϴ�.
	void f1()       { std::cout << "f1" << std::endl; }
	void f1() const { std::cout << "f1 const" << std::endl; }
};
int main()
{
	Sample s;
	const Sample cs;

	s.f1();	// ��� ��ü�� �ƴѰ��
			// 1. non-const �� ����մϴ�.
			// 2. non-const ������ ���ٸ� const ������ ����մϴ�.

	cs.f1(); // ��� ��ü�� ���
			 // => const ������ ��밡�� �մϴ�.("f1 const")
}