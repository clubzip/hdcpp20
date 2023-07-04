#include <iostream>
#include <type_traits>

// if (조건)  : 실행시간 제어문,  조건이 거짓이면 실행되지 않음. 
//			    조건이 거짓이어도 "템플릿 => C++함수" 에는 포함됨

// if (조건) constexpr : 컴파일 시간 제어문
// => 조건이 거짓이면 "템플릿 => C++함수" 에는 포함안됨!
// => C++17 에서 등장한 기술
// => 템플릿 만들때 널리 사용!!

template<typename T> 
void printv(const T& value)
{
//	if ( std::is_pointer<T>::value )
	if constexpr (std::is_pointer<T>::value)
		std::cout << value << " : " << *value << std::endl;
	else
		std::cout << value << std::endl;
}


int main()
{
	int n = 10;
	printv(n);
	printv(&n);
}