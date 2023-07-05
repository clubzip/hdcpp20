#include <iostream>

class Point
{
	int x, y;
public:
	// 핵심 1. 멤버 함수는 호출할때 this 가 추가되게 됩니다.
	void set(int a, int b) // void set(Point* this, int a, int b)
	{
		x = a;	// this->x = a;
		y = b;  // this->y = b;
	}
	// C++23 : 아래 처럼 만드는 문법 등장 - 내일 설명
	// void set(this Point& self, int a, int b) {}

	// 핵심 2. static 멤버 함수는 this가 추가되지 않습니다.
	static void foo(int a) {}
};

int main()
{
//	Point pt;	// Point* p = malloc(sizeof(Point))
				// call Point::Point(p);

	Point::foo(10); // 컴파일 해도 "foo(10)"

	Point p1;
	Point p2;

	p1.set(10, 20); // 이 코드의 원리는 ?
				    // set(&p1, 10, 20) 으로 변경됩니다.
					// 즉, 객체가 함수 인자 처럼 전달됩니다.
					// 인자가 전달되는 방식과 객체가 전달되는 방식이
					// 완전히 동일하지는 않습니다.
}