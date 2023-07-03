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
	// new 가 하는 일
	// 1. 메모리 할당
	// 2. 생성자 호출
//	Point* p = new Point(1, 2);

	// delete 가 하는일
	// 1. 소멸자 호출
	// 2. 메모리 해지
//	delete p;


	// C++ 에서는 "메모리 할당" 과 "생성자 호출"을 분리해서 하는 경우가 많습니다.
	// 1. 생성자 호출없이 메모리만 할당
	Point* p1 = static_cast<Point*>( operator new(sizeof(Point)) );


	// 2. 이미 할당된 메모리에 생성자만 호출
	// => placement new 라고 불리는 C++98 시절부터 있던 아주 유명한 기술
//	new(p1) Point(1, 2);
	std::construct_at(p1, 1, 2); // C++20 부터 지원
								 // 위와 완전히 동일한 코드


	// 3. 메모리 해지 없이 소멸자만 호출
//	p1->~Point();
	std::destroy_at(p1); // 위와 완전히 동일한 코드 
						 // C++17 부터 지원


	// 4. 메모리만 해지
	operator delete(p1);
}
