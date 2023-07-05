#include <iostream>
#include <vector>
#include <string>

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

	std::cout << ret << std::endl;
}