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
	// => 아래 코드에서 (A), (B), (C)가  실행되는 순서는 정의 되어있지않습니다.
	// => B, A, C 순서로 실행되면 안전합니다.
	// => B, C, A 순서로 실행되고, goo() 에서 예외 나오면
	//				=> B 에서 할당한 메모리는 누수가 됩니다.

	// 핵심 : 자원을 할당하면 어떠한 다른일을 하기 전에 반드시
	//       자원 관리 객체(스마트포인터)에 넘겨야 합니다.
	//       중간에 다른 작업이 발생하면 안됩니다.
	foo( std::shared_ptr<int>(new int), goo() );
	//		(A)					(B)      (C)


	// 그런데. 아래 처럼 하면 항상 안전합니다.
	// std::make_shared<int>() : 1. 내부적으로 new int 하고
	//							 2. 할당된 주소를 관리하는 스마트포인터반환
	foo(std::make_shared<int>(), goo());
	//	    (A)					 (B) 










	// 스마트 포인터 배열 버전 사용
	std::unique_ptr<int> up1(new int);	
	std::unique_ptr<int> up2(new int[10]);

	std::shared_ptr<int> sp1(new int);	
	std::shared_ptr<int> sp2(new int[10]);
			
}
