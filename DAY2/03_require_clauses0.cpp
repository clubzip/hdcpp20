#include <iostream>

// 참고 ) 동일 이름의 일반함수와 함수 템플릿이 있을때 규칙
template<typename T> 
void foo(T a)   { std::cout << "T" << std::endl; }

// void foo(int a) { std::cout << "int" << std::endl; }

int main()
{
	foo(3); // 1. int 사용. exactly matching 
			// 2. int 버전이 없으면 템플릿 사용
}