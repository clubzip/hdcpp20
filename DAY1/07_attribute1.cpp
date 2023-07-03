#include <iostream>

// attribute 문법 
// => C++11 에서 도입된 문법
// => [[ ]]  로 표기
// => 컴파일러에게 다양한 것을 지시하는 문법

// C++ 버전별로 계속 추가되고 있음

// [[nodiscard]] : 반환 값을 무시하는 경우 경고를 발생해 달라
//					C++17
// 
// C++20 에서 4개 추가
// [[nodiscard(msg)]] 
// [[likely]]
// [[unlikely]]
// [[no_unique_address]]

[[nodiscard("my message")]] int* allocate(int size)
{
	return new int[size];
}

int main()
{
	allocate(10);
}
