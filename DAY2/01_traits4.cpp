#include <iostream>

// 핵심 1. C++11 의 type_traits 기술을 사용하기위한 헤더
#include <type_traits>

// C++14 에서 아래 alias 가 표준에 추가되었습니다.
template<typename T>
using remove_pointer_t = typename std::remove_pointer<T>::type;


// C++17 에서 아래 변수가 도입니다. 
// "using alias" 가 아닌 "variable template" 이라는 C++17 문법사용
template<typename T>
constexpr bool is_pointer_v = std::is_pointer<T>::value;

template<typename T>
void foo(T a)
{
	// 핵심 2. 타입의 특성을 조사
	bool b1 = std::is_pointer<T>::value;  // C++11
	bool b2 = std::is_pointer_v<T>;       // C++17 에서 도입된 기술


	// 핵심 3. T에서 변형된 타입얻기 - ::type 이 타입 이므로 "typename 필요"
	typename std::remove_pointer<T>::type n; // C++11
	std::remove_pointer_t<T> n1;			 // C++14 부터 지원
}


int main()
{
	int n = 0;
	foo(&n);
}