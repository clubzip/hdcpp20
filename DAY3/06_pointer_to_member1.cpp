#include <iostream>

class Point
{
	int x, y;
public:
	// �ٽ� 1. ��� �Լ��� ȣ���Ҷ� this �� �߰��ǰ� �˴ϴ�.
	void set(int a, int b) // void set(Point* this, int a, int b)
	{
		x = a;	// this->x = a;
		y = b;  // this->y = b;
	}
	// C++23 : �Ʒ� ó�� ����� ���� ���� - ���� ����
	// void set(this Point& self, int a, int b) {}

	// �ٽ� 2. static ��� �Լ��� this�� �߰����� �ʽ��ϴ�.
	static void foo(int a) {}
};

int main()
{
//	Point pt;	// Point* p = malloc(sizeof(Point))
				// call Point::Point(p);

	Point::foo(10); // ������ �ص� "foo(10)"

	Point p1;
	Point p2;

	p1.set(10, 20); // �� �ڵ��� ������ ?
				    // set(&p1, 10, 20) ���� ����˴ϴ�.
					// ��, ��ü�� �Լ� ���� ó�� ���޵˴ϴ�.
					// ���ڰ� ���޵Ǵ� ��İ� ��ü�� ���޵Ǵ� �����
					// ������ ���������� �ʽ��ϴ�.
}