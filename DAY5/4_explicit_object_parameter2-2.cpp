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

	s.f1();
	cs.f1();
}