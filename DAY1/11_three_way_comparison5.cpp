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
};

int main()
{
	Rect r1(1, 1, 10, 10);
	Rect r2(2, 2, 11, 11);

	auto ret = (r1 <=> r2);
}