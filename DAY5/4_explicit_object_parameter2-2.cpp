#include <iostream>

class Sample
{
public:
	// 핵심 : 동일이름의 함수를 const, non-const 로 동시에 
	//       만들수 있습니다.
	void f1()       { std::cout << "f1" << std::endl; }
	void f1() const { std::cout << "f1 const" << std::endl; }
};
int main()
{
	Sample s;
	const Sample cs;

	s.f1();	// 상수 객체가 아닌경우
			// 1. non-const 를 사용합니다.
			// 2. non-const 버전이 없다면 const 버전을 사용합니다.

	cs.f1(); // 상수 객체인 경우
			 // => const 버전만 사용가능 합니다.("f1 const")
}