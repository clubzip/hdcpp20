#include <iostream>

// C++ 진영에서는 "함수 객체" 를 아주 널리 사용합니다.
// => C++20 에서 추가된 모든 알고리즘은 "함수" 가 아닌 "함수 객체" 입니다.

// 함수 객체 : () 연산자를 재정의해서 함수 처럼 사용가능한것!

class less
{
public:
	bool operator()(int a, int b) 
	{
		return a < b;
	}
};
int main()
{
	less f;
	bool b1 = f(1, 2);
	bool b2 = f.operator()(1, 2); // 직접 이렇게 사용해도 됩니다.
}