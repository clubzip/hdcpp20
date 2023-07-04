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

	// �Ϲ� ���� ������
	// Point<double> p3 = p1 ���� p1 �� Point<double>  �ΰ�츸 ����
//	Point(const Point& p)    : x(p.x), y(p.y) {} // �� �����
//	Point(const Point<T>& p) : x(p.x), y(p.y) {} // ���ڵ�� ����

	// Point<int> �� ������ �ְ� �Ϸ���
	// => �Ʒ� ó�� �ϸ� �׻� ���ڷ� Point<int> �� ����.!
	// Point(const Point<int>& p) : x(p.x), y(p.y) {}

	// �Ʒ� ó�� �ϸ� ���ڷ� Point<����Ÿ��> �� ������ ������ �Դϴ�.
	// => Generic �����ڶ�� �Ҹ��� ���
	template<typename U>
	Point(const Point<U>& p) : x(p.x), y(p.y) {}


	// ��� ������ Point ������ ģ�� �̴�.(private ���� �����ϰ�)
	template<typename> friend class Point;
};

int main()
{
	Point<int> p1(1, 2);
	Point<int> p2 = p1;    // ok. ���� ������

	Point<double> p3 = p1; // p3 �� p1�� �ٸ� Ÿ���Դϴ�.

}