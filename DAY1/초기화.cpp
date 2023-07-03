#include <iostream>

// C++11
// 1. 어떠한 생성자가 없고 <== 핵심
// 2. 모든 멤버가 public 이면
// 구조체 처럼 초기화 가능합니다
// ( .x = 10  의 표기법은 C++20 부터)

// C++11 STL의 array
template<typename T, int N>
struct array
{
	T buff[N];
};
int main()
{
	array<int, 5> a = { 1,2,3,4,5 };
}