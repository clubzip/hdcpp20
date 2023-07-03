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

//	array(const array& other) {}
//	array() {}

	int size() const { return N; }
};

int main()
{
	array<int, 5> a = { 1,2,3,4,5 };
			// => 이런 표기법이 되게 하려면 의도적으로
			//	  어떠한 생성자도 만들지 말아야 합니다(복사 생성자, move 생성자등)
}