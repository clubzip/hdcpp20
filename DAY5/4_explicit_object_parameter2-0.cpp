#include <iostream>

// const member function �� explicit object paramter

// �ٽ� 1. C++ ���� ��ü�� 2���� ���°� �ֽ��ϴ�.
// => �Ϲ�(non-const) ��ü : ���� ������ �����մϴ�.
// => ���(const)     ��ü : ���� ������ �ȵ˴ϴ�.


// �ٽ� 2. 
//				non-const ��� �Լ�,     const ��� �Լ�
// ������ü     O (ȣ�Ⱑ��)             O (ȣ�Ⱑ��)
// ��� ��ü      X (ȣ��ȵ�)				O (ȣ�Ⱑ��)


// �ٽ� 3. print ���� ���(x,y)�� �б⸸ �ϸ�
// => �ݵ�� const member �Լ��� �ؼ�. ��� ��ü�� ��밡���ϰ� �ؾ� �մϴ�

// C++ �� ������� : ��� ��ü�� �ִٴ� ��.
// swift, java, c# => ��ü�� ��� new �� ���� ����. ��� ��ü ������ ����.


class Point
{
	int x, y;
public:
	Point(int x, int y) :x(x), y(y) {}

	void set(int a, int b) // void set(Point* this, int a, int b)
	{
		x = a;
		y = b;
	}
//	void print()       // void print(Point* this)
	void print() const // void print(const Point* this)
	{ 
//		x = 10; // this->x = 10 �ε�, this �� ����� ����Ű�� ������ �̹Ƿ� error

		std::cout << x << ", " << y << std::endl; 
	}
};
int main()
{
	Point pt(1, 1);  // non-const object
	const Point cpt(1, 1); // const object

	pt.set(10, 20);	 // ok. pt �� ����� �ƴϹǷ� set ȣ�� ����
					 // set(&pt, 10, 20) �ε�, pt�� const �ƴϹǷ� ok

	cpt.set(10, 20); // error. cpt�� ��� ��ü�̹Ƿ� set ȣ�� �ȵ�.
					 // set(&cpt, 10, 20) �ε�, cpt�� const �̹Ƿ� error

	// set   : ���������� x, y �� �����ϹǷ� ��� ��ü�� ȣ���Ҽ� ����� �մϴ�
	// print : ���������� x, y �� �������� �ʽ��ϴ�. ��� ��ü�� ȣ�Ⱑ���ؾ� �մϴ�.

	pt.print();
	cpt.print();
}