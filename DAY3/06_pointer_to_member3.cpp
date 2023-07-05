#include <iostream>
#include <functional>

struct Point
{
	int x;
	int y;
};

int main()
{
	int n = 10;
	int* p1 = &n; // int 형 변수 n 의 주소를 담는 포인터 변수 p1


	// 핵심 1. pointer to member data
	// 아래 코드가 멤버 변수에 대한 포인터 입니다. 
	// => 멤버 함수는 객체가 없어도 "코드메모리에 존재" 하지만!!
	// => 멤버 변수는 객체가 없으면 "메모리에 없는것 아닌가요 ?"
	int Point::*p2 = &Point::y;
				// => Point 안에서 y 가 몇번째 있는지 offset
		
	printf("%d\n", p2); // 4


	// 핵심 2. pointer to member data 사용하기 => "*." 사용
	// *p2 = 10; // error. 객체가 없습니다.

	Point pt;
	pt.*p2 = 20;  // pt.y = 20  ok 


	// 핵심 3. pointer to member data 도 callable object 입니다.

	// (pt.*p2)() = 20; // error. p2는 함수 포인터가 아닙니다.
					 //		   멤버 변수의 포인터 입니다.

	// 그런데, 멤버 변수 포인터도 invoke 됩니다.
	std::invoke(p2, &pt) = 20;
				// pt.*p2 = 20 즉 pt.y = 20
}

// "callable object" 라는 용어의 정의
// => std::invoke() 로 호출할수 있는 객체
// => 함수, 함수 포인터, 함수에 대한 참조
//    멤버함수, 멤버 함수 포인터, 멤버 함수에 대한 참조
//    () 연산자를 재정의한 객체, 람다 표현식
//	  멤버 변수에 대한 포인터 <<=== 이 부분을 알아 두세요.