#include <iostream>

int foo();// { return 0; }

int main()
{
	// 참고 : 평가되지 않은 표현식(unevaluated expression)
	int n2 = sizeof( foo() ); // sizeof( 함수 호출표현식 )
							  // "함수 호출식 foo()" 의 결과로 나오는 값의 크기
						      // 결국 int 값이므로 4

	decltype( foo() ) n3; // foo() 의 결과로 나오는 타입과 동일 타입의 변수 n3선언

	// 위에 있는 "foo()" 표현식은 실제로 함수를 호출하지는 않습니다.
	// => 이런 것들을 C++에서는 "평가 되지 않은 표현식" 이라고 합니다.
	// => 4개가 있습니다.
	// sizeof( 표현식 )
	// decltype(표현식)
	// typeid( 표현식 )
	// noexcept(표현식)


	// 1. C++20 전에는 람다표현식은 평가되지 않은 표현식에 넣을수 없었습니다.
	int n = sizeof( [](int a, int b) { return a + b; } );

	decltype( [](int a, int b) { return a + b; } ) f; // C++17까지는 에러
													  // C++20 부터 가능


	// 2. C++17 까지 람다 표현식이 만드는 타입은 디폴트 생성자가 없습니다
	//    C++20 부터는 캡쳐 하지 않은 람다에 한해서 디폴트 생성자 제공
	auto add = [](int a, int b) {};

	decltype(add) f2;	// C++20 은 에러 아님. 디폴트 생성자 가능
						// C++20 이전은 에러.
}