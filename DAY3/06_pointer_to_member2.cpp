#include <iostream>
#include <functional> // C++17 의 std::invoke 사용..
class Dialog
{
public:
	void close1(int a) {}
	static void close2(int a) {}
};
void foo(int a) {}

// 핵심 : 멤버 함수와 함수 포인터
// 1. 일반 함수 포인터에 멤버 함수의 주소를 담을수 없다. - this 때문에 
// 2. 일반 함수 포인터에 static 멤버 함수의 주소는 담을수 있다.
int main()
{
	void(*f1)(int) = &foo;				// ok
//	void(*f2)(int) = &Dialog::close1;	// error. close1은 this가 추가되는 함수
	void(*f3)(int) = &Dialog::close2;	// ok


	// 핵심 3. 멤버 함수 주소를 담는 포인터를 만드는 방법 
	void(Dialog::*f2)(int) = &Dialog::close1;

	// 핵심 4. 멤버 함수 포인터로 함수 호출하는 방법
//	f2(10); // 멤버 함수는 호출하려면 객체(this)가 필요한데..
			// 이 코드는 객체가 없다.

	Dialog dlg;
//	dlg.f2(10); // error. 
				// dlg 안에서 f2라는 이름을 찾는데, f2라는 멤버는 없다.

	// 이때 사용하는 연산자가 "pointer to member" 라는 .* ->* 연산자
	// .* : 한개의 연산자, C에는 없는 C++ 전용
//	dlg.*f2(10);// error. 연산자 우선순위가 .* 보다 ( 빠르다.

	(dlg.*f2)(10);	// ok!! () 를 사용해서 우선순위 높인것!!
					// 이 표기법이 멤버 함수 포인터로 함수 호출하는 표기법

	// 핵심 5. 함수 호출 표현식의 일반화!!
	f1(10);			// 멤버가 아닌 일반함수 포인터로 함수 호출
	(dlg.*f2)(10);	// 멤버 함수 포인터로 함수 호출!

	// C++17 에서 도입된 std::invoke() 사용
	std::invoke(f1, 10);		// f1(10)
	std::invoke(f2, &dlg, 10);	// (dlg.*f2)(10);
}