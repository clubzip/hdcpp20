#include <iostream>
#include <ranges>

// std::ranges::begin 의 장점 1. 

// 사용자가 직접 컨테이너를 만들었는데.. 

// 1. begin/end 를 멤버 함수로 만든 경우
struct MyContainer1
{
	int* begin() { return 0; }
	int* end() { return 0; }
};
// 2. begin/end 를 일반 함수로 만든 경우
struct MyContainer2
{
};
int* begin(MyContainer2& mc) { return 0; }
int* end(MyContainer2& mc) { return 0; }

int main()
{
	MyContainer1 mc1;
	MyContainer2 mc2;

	// 1. 사용자가 만든 begin 을 직접 호출할때
	auto a1 = mc1.begin(); // ok
	auto a2 = begin(mc2);  // ok

	// 2. std::begin() 을 사용할때
	auto p1 = std::begin(mc1); // ok. 원리는 mc1.begin() 를 다시 호출
//	auto p2 = std::begin(mc2); // error. 

	// 3. std::ranges::begin() 은 모두 가능.
	auto p3 = std::ranges::begin(mc1);
	auto p4 = std::ranges::begin(mc2);
}
