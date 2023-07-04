#include <list>
#include <vector>
#include <concepts>
#include <algorithm>
#include <iostream>
#include <string>


template<typename T>
class Point
{
	T x, y;
public:
	Point(T a, T b) :x(a), y(b) {}

	/*
	template<typename U>
	Point(const Point<U>& p) : x(p.x), y(p.y) {}
	*/

	// 위 코드와 아래 코드에서 각각의 경우에 에러 메세지 확인해 보세요
	// => 아래 코드의 에러가 훨씬 읽기 좋습니다.

	// U 타입이 T 타입으로 변환 가능할 때만 아래 함수를 사용합니다.
	template<typename U> requires std::is_convertible_v<U, T>
	Point(const Point<U>& p) : x(p.x), y(p.y) {}

	template<typename> friend class Point;
};

int main()
{
	Point<std::string> p1("1", "2");

	Point<double> p2 = p1; 
}