#include <iostream>
#include <type_traits>
#include <vector>


// traits : 타입에 대한 특성을 조사하는 기술, 
//          template 부분 특수화 문법으로 만든다.
//			"is_xxx" 처럼 만들어서 사용

// concept : 타입에 대한 정의(개념의 표현), C++20
//			concept 문법 사용
//			"is_" 를 사용하지 말라고 권장



template<typename T>
//concept container = requires(T c) // 배열을 "값 타입(T)" 로 받으면 포인터로 받게 됩니다.
concept container = requires(T& c)  // 이렇게 받으면 배열을 인자로 받을때 T가 배열 입니다.
{
	// 구현 방법 1. begin(), end() 멤버 함수가 있어야 한다.
	// c.begin();
	// c.end();

	// 구현방법 2. std::begin()에 인자로 전달 가능해야 한다.
	std::begin(c);
	std::end(c);
};

template<typename T> void check(T& c)
{
	// concept이름<타입> 하면 만족하는지 조사 가능합니다.
	bool b = container<T>;
	std::cout << b << std::endl;
}

int main()
{
	std::cout << std::boolalpha;
	int n = 0;
	std::vector<int> v = { 1,2,3 };
	int x[3] = { 1,2,3 };

	check(n); // false
	check(v); // true
	check(x); // ?
}