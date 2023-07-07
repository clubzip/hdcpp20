#include <iostream>

// const member function 과 explicit object paramter

// 핵심 1. C++ 에서 객체를 2가지 형태가 있습니다.
// => 일반(non-const) 객체 : 상태 변경이 가능합니다.
// => 상수(const)     객체 : 상태 변경이 안됩니다.

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
//		x = 10; // this->x = 10 인데, this 가 상수를 가리키는 포인터 이므로 error

		std::cout << x << ", " << y << std::endl; 
	}
};
int main()
{
	Point pt(1, 1);  // non-const object
	const Point cpt(1, 1); // const object

	pt.set(10, 20);	 // ok. pt 는 상수가 아니므로 set 호출 가능
					 // set(&pt, 10, 20) 인데, pt가 const 아니므로 ok

	cpt.set(10, 20); // error. cpt는 상수 객체이므로 set 호출 안됨.
					 // set(&cpt, 10, 20) 인데, cpt가 const 이므로 error

	// set   : 내부적으로 x, y 를 수정하므로 상수 객체는 호출할수 없어야 합니다
	// print : 내부적으로 x, y 를 수정하지 않습니다. 상수 객체도 호출가능해야 합니다.

	pt.print();
	cpt.print();
}