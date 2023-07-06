#include <iostream>
#include <memory>

int goo() { return 10; }
void foo(std::shared_ptr<int> sp, int n) {}

int main()
{
	// C++ 표준 스마트 포인터 사용시
	// => 직접 new 하지말고
	// => std::make_shared<> 를 사용하는 것이 좋습니다.

	std::shared_ptr<int> p1(new int);				   // bad
	std::shared_ptr<int> p2 = std::make_shared<int>(); // good

	std::unique_ptr<int> p3(new int);				   // bad
	std::unique_ptr<int> p2 = std::make_unique<int>(); // good

	// 왜 make_shared 가 좋은 가요 ?
	foo( std::std::shared_ptr<int>(new int), goo() );





	// 스마트 포인터 배열 버전 사용
	std::unique_ptr<int> up1(new int);	
	std::unique_ptr<int> up2(new int[10]);

	std::shared_ptr<int> sp1(new int);	
	std::shared_ptr<int> sp2(new int[10]);
			
}
