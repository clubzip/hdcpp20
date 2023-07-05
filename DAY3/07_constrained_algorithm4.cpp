#include <iostream>
#include <vector>
#include <string>

// 현재 코드는 projection 에 멤버 함수 뿐 아니라 멤버 데이타도 됩니다.

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

	// Point 자체는 크기 비교가 안됩니다. 하지만 int 인 y 로는 크기비교가능
	// 즉, 3번째 인자로 멤버 함수가 아닌 멤버 데이타도 사용가능.
	auto ret = Max(p1, p2, &Point::y);
}