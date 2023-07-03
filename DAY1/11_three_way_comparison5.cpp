#include <iostream>
#include <compare>

class Rect
{
	int x, y, w, h;
public:
	Rect(int x, int y, int w, int h)
		: x(x), y(y), w(w), h(h)
	{
	}
	// 사각형의 동일성, 순서 비교 를 어떻게 구현할 것인가요 ?
	// => 면적으로 비교 하기로 했다!!

	// std::strong_ordering : 2개의 객체가 "같음"을 나타낼때 사용하세요
	// std::weak_ordering   : 2개의 객체가 "대등함"을 나타낼때 사용하세요
	std::weak_ordering operator<=>(const Rect& r) const
	{
		return (w * h) <=> (r.w * r.h);
	}
};

int main()
{
	Rect r1(1, 1, 10, 10);
	Rect r2(2, 2, 11, 11);

	auto ret = (r1 <=> r2);
}