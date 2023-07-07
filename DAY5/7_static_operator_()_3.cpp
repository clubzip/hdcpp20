#include <iostream>

class less
{
public:
	bool operator()(int a, int b)
	{
		return a < b;
	}

	using F = bool(*)(int, int);


	static bool helper(int a, int b)
	{
		return a < b;
	}
	operator F() { return &less::helper; }
};

int main()
{
	// 람다표현식은 함수 포인터로 암시적 변환 될수 있습니다.
	bool(*f)(int, int) = [](int a, int b) { return a < b; };

}