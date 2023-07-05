#include <iostream>
#include <functional>

// 함수 객체 ( function object )
// => () 연산자를 재정의해서 함수 처럼 사용 가능한 객체
// => 일반 함수보다 여러가지 장점이 있다.

struct plus
{
	int operator()(int a, int b) const
	{
		return a + b;
	}
};

int main()
{
	plus p;

	int n = p(1, 2); // p.operator()(1,2)
}