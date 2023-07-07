#include <iostream>

// C++23 의 Big 1 : Explicit Object Parameter
// => 흔히 별명으로 "Deducing this" 라고 부릅니다.

class Sample
{
	int x, y;
public:
	// 아래 함수는 결국	       컴파일러에 의해 아래처럼 변경됩니다
	void f1(int a, int b)	// void f1(Sample* this, int a, int b)
	{
		std::cout << "f1" << std::endl;
	}

	// C++23 부터 객체를 명시적으로 받는 문법이 도입됩니다.
	// => 아래 코드에서 "self" 는 변수 이름입니다. 아무이름이나 상관없습니다.
	// => Python 과 유사한 형태입니다.
	void f2(this Sample& self, int a, int b)
	{
//		x = a; // error
		self.x = a; // ok
		self.y = b;

		std::cout << "f2" << std::endl;
	}
};

int main()
{
	Sample s;
	s.f1(1, 2);	// f1(&s, 1, 2)
	s.f2(1, 2); // f2(s, 1, 2)
}