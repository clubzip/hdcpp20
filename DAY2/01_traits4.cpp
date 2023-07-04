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

	// QA. const int& 에서 const 와 & 를 모두 제거하려면
	// C++11
	std::remove_const_t< std::remove_reference_t<const int&> > n1;
	// => 정답

	// 아래 코드는 그 아래의 포인터를 생각해보세요
	std::remove_reference_t< std::remove_const_t<const int&> > n2;

	// const int* const p;	// 앞 const : 가리키는 곳이 const
							// 뒤 const : p가 const
	std::remove_pointer_t< std::remove_const_t<const int* const>> n3;
				// 뒤의 const 만 제거.. 

	// reference 정체 : const pointer 입니다.

	int& r1 = n;		// int* const r1 = &n 입니다.
	const int& r2 = n;  // const int* const r2 = &n 입니다.

	// C++20 에서는 remove_cvref 가 추가 되었습니다.
	// remove_const : const 를제거
	// remove_cv    : const, volatile 제거
	// remove_reference : reference 제거
	// remove_cvref : const, volatile, reference 제거 - C++20

}