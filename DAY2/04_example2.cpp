#include <iostream>
#include <algorithm>
#include <type_traits>
#include <concepts>
#include <vector>

// ordering
template<typename T> 
concept Concept1 = sizeof(T) >= 4; 


template<typename T> 
concept Concept2 = std::is_integral_v<T>; 


template<typename T> 
concept Concept3 = Concept1<T> && Concept2<T>; 


template<typename T> requires Concept1<T>
void foo(T a)
{
	std::cout << "1" << std::endl;
}

// 타입이 조건을 만족하는 템플릿이 2개 이상 있을때
// => 보다 많은 조건을 만족하는 템플릿이 있다면 에러가 아니고 해당 버전을 사용합니다.
// 
// 1번 foo : Concept1<T>
// 2번 foo : Concept1<T> && Concept2<T>
// 
//template<typename T> requires Concept2<T>
template<typename T> requires Concept3<T>
void foo(T a)
{
	std::cout << "2" << std::endl;
}

int main()
{
	foo(3);
//	foo(3.4); 
}