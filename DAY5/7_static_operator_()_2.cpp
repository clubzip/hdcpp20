#include <iostream>

class less
{
public:
	bool operator()(int a, int b)
	{
		return a < b;
	}

	using F = bool(*)(int, int);

	// 아래 함수가 "변환연산자" 라는 함수 입니다. 
//	operator F() { return 함수주소; }

	operator F() { return &less::operator(); }
};



int main()
{
	less f;

	// 결국 f 는 이항 함수 입니다.
	// 아래 처럼 사용할수 있을까요 ?
	// (함수 포인터가 필요한 곳에 f를 보낼수 있을까??)
	bool(*p)(int, int) = f;
			// => f 안에 변환 연산자 를 추가하면 됩니다.
			// => f.operator 함수포인터타입()
}