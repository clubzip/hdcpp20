#include <iostream>


class Point
{
	int x, y;
public:
	Point(int x, int y) :x(x), y(y) {}

	/*
	void set(int a, int b)
	{
		x = a;
		y = b;
	}
	void print() const 
	{
		std::cout << x << ", " << y << std::endl;
	}
	*/
	// 위 2개의 멤버 함수를 "explicit object parameter" 문법으로 
	// 만들어 보세요


};
int main()
{
	Point pt(1, 1);  
	const Point cpt(1, 1); 

	pt.set(10, 20);	 
	
//	cpt.set(10, 20); 

	pt.print();
	cpt.print();
}