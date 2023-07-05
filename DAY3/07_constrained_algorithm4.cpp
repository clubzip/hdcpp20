#include <iostream>
#include <vector>
#include <string>

// ���� �ڵ�� projection �� ��� �Լ� �� �ƴ϶� ��� ����Ÿ�� �˴ϴ�.
// projection ����
// 1. �����Լ�
// 2. ���ڰ� ���� ��� �Լ� �ּ�
// 3. ��� ����Ÿ�� �ּҸ� ���� �����մϴ�.(� ����� �� �Ұ��ΰ�?)

struct Point
{
	int x, y;
};

template<typename T, typename Projection >
const T& Max(const T& a, const T& b, Projection proj)
{
	return std::invoke(proj, a) < std::invoke(proj, b) ? b : a;										// (b.*proj)()
}

int main()
{
	Point p1 = { 1, 10 };
	Point p2 = { 5, 3 };

	// Point ��ü�� ũ�� �񱳰� �ȵ˴ϴ�. ������ int �� y �δ� ũ��񱳰���
	// ��, 3��° ���ڷ� ��� �Լ��� �ƴ� ��� ����Ÿ�� ��밡��.
	auto ret = Max(p1, p2, &Point::y); // p1.y < p2.y
}