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
	// new �� �ϴ� ��
	// 1. �޸� �Ҵ�
	// 2. ������ ȣ��
//	Point* p = new Point(1, 2);

	// delete �� �ϴ���
	// 1. �Ҹ��� ȣ��
	// 2. �޸� ����
//	delete p;


	// C++ ������ "�޸� �Ҵ�" �� "������ ȣ��"�� �и��ؼ� �ϴ� ��찡 �����ϴ�.
	// 1. ������ ȣ����� �޸𸮸� �Ҵ�
	Point* p1 = static_cast<Point*>( operator new(sizeof(Point)) );


	// 2. �̹� �Ҵ�� �޸𸮿� �����ڸ� ȣ��
	// => placement new ��� �Ҹ��� C++98 �������� �ִ� ���� ������ ���
//	new(p1) Point(1, 2);
	std::construct_at(p1, 1, 2); // C++20 ���� ����
								 // ���� ������ ������ �ڵ�


	// 3. �޸� ���� ���� �Ҹ��ڸ� ȣ��
//	p1->~Point();
	std::destroy_at(p1); // ���� ������ ������ �ڵ� 
						 // C++17 ���� ����


	// 4. �޸𸮸� ����
	operator delete(p1);
}
