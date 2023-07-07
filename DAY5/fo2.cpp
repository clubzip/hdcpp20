// fo1.cpp
#include <iostream>
#include <vector>
#include <algorithm>

bool foo(int n)
{
	return n % 3 == 0;
}

struct IsMod
{
	// 핵심 : 함수 객체는 클래스 이므로 멤버 데이타가 있습니다.
	//	     흔히 상태를 가지는 함수 라고 합니다.
	int value;	
	IsMod(int n) : value(n) {}

	bool operator()(int n) const { return n % value; }
};

int main()
{
	std::vector v = { 1,6,3,7,8 };

	int k = 3; 

	IsMod f(k); // f는 단항함수(인자가 한개인 함수) 인데..
				// 내부적으로 k 값을 보관합니다.

	auto ret3 = std::find_if(v.begin(), v.end(), f );
}