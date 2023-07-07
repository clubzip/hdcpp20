// fo5
#include <iostream>

// 함수객체의 장점을 알았다면!!
// 함수객체를 제대로 만들어 봅시다.

struct plus
{
	inline int operator()(int a, int b) const
	{
		return a + b;
	}
};

int main()
{
	plus p;

	int n = p(1, 2);
}