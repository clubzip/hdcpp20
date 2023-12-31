#include <iostream>

template<typename ... ARGS> void foo(int a1, ARGS&& ... args)
{
	int v1 = 10, v2 = 10;

	// 람다 표현식에서 과 지역변수 캡쳐.
	// 1. 람다 표현식에서 지역변수를 사용하려면 캡쳐 하면 됩니다. - C++11
	auto f1 = [ v1, v2 ](int x) { return x + v1 + v2; };
	
	// 2. 함수 인자도 결국 지역변수 입니다. 캡쳐 가능합니다. - C++11
	auto f2 = [ v1, a1 ](int x) { return x + v1 + a1; };
	
	// 3. C++20 부터. 가변인자 템플릿의 "파라미터 팩"도 캡쳐 가능합니다.
	auto f3 = [ ...args = std::forward<ARGS>(args) ](int a)
	{
		(std::cout << ... << args); // C++17 fold expression
	};
	f3(10);
}

int main()
{
	int a1 = 1, a2 = 2, a3 = 3;
	foo(0, a1, a2, a3);
}

// C++20 에서 람다 표현식의 변화

// 1. 람다 표현식에 template  사용가능
// 2. 평가 되지 않은 표현식에 넣을수 있고
// 3. 람다 표현식이 만드는 타입에 디폴트 생성자가 있고
// 4. 가변인자 템플릿의 파라미터 팩도 캡쳐 가능하고
// 5. [=] 캡쳐가 this 캡쳐했던것을 제거.