#include <iostream>

class Sample
{
	int value;
public:
	void foo()
	{
		// 람다표현식에서 멤버 데이타 사용하기.

		// 1. this 를 캡쳐하면 멤버 데이타에 접근 가능합니다 - C++11
		auto f1 = [this](int a) { return a + value; }; // ?

		// 2. this 대신 = 로 캡쳐해도 멤버데이타 접근 가능합니다.
		// = 캡쳐 : 모든 지역변수를 캡쳐 하겠다는 의미
		auto f2 = [=](int a) { return a + value; }; // ?
				// C++17 까지는 가능.
				// C++20 부터는 사용금지 되었습니다.
				// 컴파일러에 따라, 에러 또는 경고 발생

		f2(0);

		// 결론 : 람다표현식에세 멤버 데이타 접근 하려면
		// 이제는 [=] 하지 말고
		// [this] 로만 하세요..
	}
};


int main()
{
	Sample s;
	s.foo();
}