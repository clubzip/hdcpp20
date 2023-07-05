#include <iostream>
#include <functional>

struct Point
{
	int x;
	int y;
};

int main()
{
	int n = 10;
	int* p1 = &n; // int �� ���� n �� �ּҸ� ��� ������ ���� p1


	// �ٽ� 1. pointer to member data
	// �Ʒ� �ڵ尡 ��� ������ ���� ������ �Դϴ�. 
	// => ��� �Լ��� ��ü�� ��� "�ڵ�޸𸮿� ����" ������!!
	// => ��� ������ ��ü�� ������ "�޸𸮿� ���°� �ƴѰ��� ?"
	int Point::*p2 = &Point::y;
				// => Point �ȿ��� y �� ���° �ִ��� offset
		
	printf("%d\n", p2); // 4


	// �ٽ� 2. pointer to member data ����ϱ� => "*." ���
	// *p2 = 10; // error. ��ü�� �����ϴ�.

	Point pt;
	pt.*p2 = 20;  // pt.y = 20  ok 


	// �ٽ� 3. pointer to member data �� callable object �Դϴ�.

	// (pt.*p2)() = 20; // error. p2�� �Լ� �����Ͱ� �ƴմϴ�.
					 //		   ��� ������ ������ �Դϴ�.

	// �׷���, ��� ���� �����͵� invoke �˴ϴ�.
	std::invoke(p2, &pt) = 20;
				// pt.*p2 = 20 �� pt.y = 20
}

// "callable object" ��� ����� ����
// => std::invoke() �� ȣ���Ҽ� �ִ� ��ü
// => �Լ�, �Լ� ������, �Լ��� ���� ����
//    ����Լ�, ��� �Լ� ������, ��� �Լ��� ���� ����
//    () �����ڸ� �������� ��ü, ���� ǥ����
//	  ��� ������ ���� ������ <<=== �� �κ��� �˾� �μ���.