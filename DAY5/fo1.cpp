// fo1.cpp
#include <iostream>
#include <vector>
#include <algorithm>

bool foo(int n)
{
	return n % 3 == 0;
}

int main()
{
	std::vector v = { 1,6,3,7,8 };

	// 1. 주어진 구간에서 3을 찾고 싶다.
	auto ret1 = std::find(v.begin(), v.end(), 3);

	// 2. 주어진 구간에서 "3의 배수" 를 찾고 싶다.
	auto ret2 = std::find_if(v.begin(), v.end(), foo);


	// 3. 주어진 구간에서 "k의 배수" 를 찾고 싶다.

	int k = 3; // 사용자가 입력한 값이라고 생각해 보세요 

	auto ret3 = std::find_if(v.begin(), v.end(), ? );
}