// 07_constrained_algorithm0
#include <vector>
#include <algorithm>

int main()
{
	std::vector v = { 1,2,3,4,5 };

	// C++98 의 STL 알고리즘 : 함수 인자로 반복자를 전달합니다.
	auto ret1 = std::find(v.begin(), v.end(), 3);


	// C++20 의 새로운 알고리즘 : 반복자도 가능하고, 컨테이너도 가능합니다.
	auto ret2 = std::ranges::find(v.begin(), v.end(), 3); // ok
	auto ret3 = std::ranges::find(v, 3);				  // ok
}