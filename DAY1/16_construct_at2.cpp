#include <iostream>
#include <algorithm>

class Point
{
	int x, y;
public:
	Point(int x, int y) : x(x), y(y) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

int main()
{
	// Point 객체 한개를 힙에 만들기
	Point* p1 = new Point(1, 2);

	// Point 객체 10개를 힙에 만들어 보세요(단, 10개가 연속된 메모리에 있어야 합니다)

}
