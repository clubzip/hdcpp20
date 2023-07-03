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
//	Point* p2 = new Point[10];	// 디폴트 생성자가 있어야 합니다.
								// Point 는 지금 디폴트 생성자 없습니다.

	// 메모리 할당과 생성자 호출을 같이 하면 유연성이 부족합니다.
	// => 메모리 할당과 생성자 호출을 분리하면 항상 편리합니다.
	
	Point* p2 = static_cast<Point*>(operator new(sizeof(Point) * 10));


	// 이제 할당된 메모리에 10개의 객체를 생성합니다.(생성자를 호출한다는 표현)
	for (int i = 0; i < 10; i++)
	{
//		new (&p2[i]) Point(0, 0); // C++98 스타일 - placement new

		std::construct_at(&p2[i], 0, 0); // C++20 스타일 
	}

	// 소멸자 호출
	for (int i = 0; i < 10; i++)
	{
//		p2[i].~Point();			   // C++98 스타일
		std::destroy_at( &p2[i] ); // C++17 스타일 
	}

	// 메모리 제거
	operator delete(p2);
}	
