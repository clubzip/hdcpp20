#include <iostream>
#include <memory>

int main()
{
	// 핵심 1. C++11
	// C++ 표준 스마트 포인터 사용시
	// => 직접 new 하지말고
	// => std::make_shared<> 를 사용하는 것이 좋습니다.

	std::shared_ptr<int> p1(new int);				   // bad
	std::shared_ptr<int> p2 = std::make_shared<int>(); // good

	std::unique_ptr<int> p3(new int);				   // bad
	std::unique_ptr<int> p2 = std::make_unique<int>(); // good


	// 2. 스마트 포인터의 배열 버전 - C++14, C++17
	std::unique_ptr<int> up1(new int);		// ok. up1 소멸자가 delete
//	std::unique_ptr<int> up2(new int[10]);  // 버그, new[] 인데..
											// 소멸자는 delete 수행

	std::unique_ptr<int[]> up2(new int[10]);// ok. 소멸자가 delete[] 수행
											// C++14


	std::shared_ptr<int>   sp1(new int);	// ok, 소멸자가 delete
	std::shared_ptr<int[]> sp2(new int[10]);// ok. 소멸자가 delete[]
											// C++17

	// 배열 버전의 스마트 포인터는 make_shared 안되나요 ?
	// => C++20 에서 도입되었습니다.
	std::shared_ptr<int[]> sp3 = std::make_shared<int[10]>(); // 10개 할당 
	std::shared_ptr<int[]> sp4 = std::make_shared<int[]>(10); // 10개 할당

	std::shared_ptr<int[]> sp3 = std::make_shared<int[10]>(1);  // 10개를 1로초기화
	std::shared_ptr<int[]> sp4 = std::make_shared<int[]>(10,1); // 10개를 1로초기화
}
