#include <iostream>

// 핵심 1. C++11 의 type_traits 기술을 사용하기위한 헤더
#include <type_traits>

template<typename T>
void foo(T a)
{
	// 핵심 2. 타입의 특성을 조사
	bool b1 = std::is_pointer<T>::value;

	// 핵심 3. T에서 변형된 타입얻기
	typename std::remove_pointer<T>::type n;
}
int main()
{
	int n = 0;
	foo(&n);
}