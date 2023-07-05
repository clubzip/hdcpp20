#include <iostream>
#include <vector>
#include <string>

// step 1. 기본 버전, 크기를 비교하는 정책을 변경할수 없습니다.
template<typename T>
const T& Max(const T& a, const T& b)
{
	return a < b ? b : a;
}

int main()
{
	std::string s1 = "ABC";
	std::string s2 = "XX";

	auto ret = Max(s1, s2);

	std::cout << ret << std::endl; // "XX"
}