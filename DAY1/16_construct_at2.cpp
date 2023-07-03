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
//	Point* p2 = new Point[10];	// ����Ʈ �����ڰ� �־�� �մϴ�.
								// Point �� ���� ����Ʈ ������ �����ϴ�.

	// �޸� �Ҵ�� ������ ȣ���� ���� �ϸ� �������� �����մϴ�.
	// => �޸� �Ҵ�� ������ ȣ���� �и��ϸ� �׻� ���մϴ�.
	
	Point* p2 = static_cast<Point*>(operator new(sizeof(Point) * 10));


	// ���� �Ҵ�� �޸𸮿� 10���� ��ü�� �����մϴ�.(�����ڸ� ȣ���Ѵٴ� ǥ��)
	for (int i = 0; i < 10; i++)
	{
//		new (&p2[i]) Point(0, 0); // C++98 ��Ÿ�� - placement new

		std::construct_at(&p2[i], 0, 0); // C++20 ��Ÿ�� 
	}

	// �Ҹ��� ȣ��
	for (int i = 0; i < 10; i++)
	{
//		p2[i].~Point();			   // C++98 ��Ÿ��
		std::destroy_at( &p2[i] ); // C++17 ��Ÿ�� 
	}

	// �޸� ����
	operator delete(p2);
}	
