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

	template<typename U>
	Point(const Point<U>& p) : x(p.x), y(p.y) {}

	template<typename> friend class Point;
};

int main()
{
	Point<std::string> p1("1", "2");

	Point<double> p2 = p1; 
}