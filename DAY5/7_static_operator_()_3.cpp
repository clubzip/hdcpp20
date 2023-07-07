#include <iostream>



int main()
{
	// 람다표현식은 함수 포인터로 암시적 변환 될수 있습니다.	
//	bool(*f)(int, int) = [](int a, int b) { return a < b; };

	// 위 한줄의 원리

	// 1. 컴파일러가 위 람다 표현식을 보고 아래 코드를 생성합니다
	class CompilerGeneratedName
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
		operator F() { return &CompilerGeneratedName::helper; }
	};


	// 2. 위 한줄은 아래 코드 입니다.
	bool(*f)(int, int) = CompilerGeneratedName();
}