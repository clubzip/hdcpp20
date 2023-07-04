#include <iostream>
#include <type_traits>
#include <vector>


template<typename T> void check(T& c)
{
	// 1. T 가 포인터 인지 조사하고 싶다.
	bool b1 = std::is_pointer<T>::value;  // C++11
	bool b2 = std::is_pointer_v<T>;       // C++17


	// 2. T 가 컨테이너인지 조사하고 싶다.

	// => 컨테이너인지 조사하는 코드는 어떻게 만들어야 할까 ?
	//    를 생각하기 전에..
	// => "컨테이너" 를 "어떻게 정의 할까"가  중요합니다.

	// concept
	// => 타입의 대한 정의를 코드로 표현하는 문법
	// => 그래서, C++ 창시자는 "is_" 로 시작하지 말라고 권장..
	// => name requiresment

}

int main()
{
	int n = 0;
	std::vector<int> v = { 1,2,3 };
	int x[3] = { 1,2,3 };

	check(n);	
	check(v);	
	check(x);   
}