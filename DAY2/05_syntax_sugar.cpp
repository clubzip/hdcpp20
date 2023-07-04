#include <concepts>
#include <iostream>

// 기본 템플릿 : 제약 조건이 없으므로 모든 타입에 대해서 사용..
template<typename T> 
void f1(T a) 
{
	std::cout << "f1" << std::endl;
}

// 제약 조건을 표기하는 방법
// 1. <> 뒤에 표기, 기본 모양
template<typename T> requires std::integral<T>
void f2(T a)
{
	std::cout << "f2" << std::endl;
}

// 2. () 뒤에 표기도 가능
template<typename T> 
void f3(T a) requires std::integral<T>
{
	std::cout << "f3" << std::endl;
}

// 3. typename 위치에 표기 가능
template< std::integral T >
void f4(T a) 
{
	std::cout << "f4" << std::endl;
}

// 4. 함수 인자 위치에 "concept_이름 auto 변수" 로 표기 가능
// => 아래 코드는 template 표기가 없지만, template 입니다.
void f5(std::integral auto a)
{
	std::cout << "f5" << std::endl;
}

// 5. 제약 조건을 제거하면 auto 만 남게 됩니다.
// => 결국 f6 은 제약조건 없는 template 입니다.
// void f6(std::integral auto a)
void f6(auto a)
{
	std::cout << "f6" << std::endl;
}

// C++20 이전 : 함수 인자로 auto 사용할수 없습니다.
// C++20 이후 : 함수 인자로 auto 사용가능 합니다. - template 입니다.

void foo(auto a) {}						// 이 코드는
template<typename T> void foo(T a) {}	// 이 코드와 완전히 동일합니다.
 

void goo(auto a) {} // 제약조건이 없는 template
void goo(std::integral auto a) {} // 제약조건이 있는 template

// sytax sugar : 문맥적 달콤함..
//			     개념은 동일한데, 편하게 사용할수 있도록
//				다른 표기법을 제공하는 것

int main()
{
	f1(10);
	f2(10);
	f3(10); 
	f4(10);
	f5(10);
}