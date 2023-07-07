// fo1.cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector v = { 1,6,3,7,8 };

	// 1. 주어진 구간에서 3을 찾고 싶다.
	auto ret1 = std::find(v.begin(), v.end(), 3);
}