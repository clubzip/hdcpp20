#include <list>
#include <vector>
#include <concepts>
#include <algorithm>
#include <iostream>


template<typename T>
class Point
{
	T x, y;
public:
	Point(T a, T b) :x(a), y(b) {}

	// 일반 복사 생성자
	// Point<double> p3 = p1 에서 p1 이 Point<double>  인경우만 가능
//	Point(const Point& p)    : x(p.x), y(p.y) {} // 이 모양은
//	Point(const Point<T>& p) : x(p.x), y(p.y) {} // 이코드와 동일

	// Point<int> 를 받을수 있게 하려면
	// => 아래 처럼 하면 항상 인자로 Point<int> 만 가능.!
	// Point(const Point<int>& p) : x(p.x), y(p.y) {}

	// 아래 처럼 하면 인자로 Point<임의타입> 이 가능한 생성자 입니다.
	// => Generic 생성자라고 불리는 기술
	template<typename U>
	Point(const Point<U>& p) : x(p.x), y(p.y) {}


	// 모든 종류의 Point 끼리는 친구 이다.(private 접근 가능하게)
	template<typename> friend class Point;
};

int main()
{
	Point<int> p1(1, 2);
	Point<int> p2 = p1;    // ok. 복사 생성자

	Point<double> p3 = p1; // p3 와 p1은 다른 타입입니다.

}