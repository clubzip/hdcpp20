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
	// Point ��ü �Ѱ��� ���� �����
	Point* p1 = new Point(1, 2);

	// Point ��ü 10���� ���� ����� ������(��, 10���� ���ӵ� �޸𸮿� �־�� �մϴ�)

}
