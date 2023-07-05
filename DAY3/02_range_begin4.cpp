#include <iostream>
#include <ranges>

// std::ranges::size() 이야기

struct MyContainer1
{
	int* begin() { return 0; }
	int* end() { return 0; }
};

int main()
{
	MyContainer1 mc1;

	auto sz0 = mc1.size();		// error. mc1 에는 size()함수 없습니다.

	auto sz1 = std::size(mc1);	// error. 결국 이코드는 mc1.size() 사용
				
	auto sz2 = std::ranges::size(mc1); // ok
		// 1. mc1.size() 가 있으면 사용
		// 2. mc1.size() 가 없으면 "mc1.end() - mc1.begin()" 이 가능하면 사용
		// 3. 반복자가 random 이 아니면 std::distance(mc1.begin(), mc1.end())

}