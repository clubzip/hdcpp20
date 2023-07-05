#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// C++20 에서는 기존에 있던 대부분의 알고리즘을 다시 만들었습니다.
// => std::ranges 안에 있습니다.

int main()
{
	std::vector<std::string> v = { "banana", "apple", "pear", "orange" };

	// 핵심 1. 반복자 버전 vs 컨테이너 버전
	std::ranges::sort(v.begin(), v.end()); // 반복자 버전
	std::ranges::sort(v);				   // 컨테이너 버전



	for (const auto& e : v)
	{
		std::cout << e << ", ";
	}

}