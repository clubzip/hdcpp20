#include <iostream>
#include <ranges>

// std::ranges::begin 의 장점 2. 

struct SomeType
{
	// int* 는 반복자 입니다.
	// int* begin() { return 0; }
	
	// int 는 반복자 아닙니다. ++로 이동하고, *로 요소 접근할수 있어야
	// 반복자 입니다
	int begin() { return 0; }
};

int main()
{
	SomeType st;

	auto p1 = std::begin(st); // st.begin()을 호출하는데.
							  // 반환 타입이 반복자인지 조사안함.

	auto p2 = std::ranges::begin(st);
						// st.begin() 의 반환 타입이
						// 반복자가 아니면 error.
}
