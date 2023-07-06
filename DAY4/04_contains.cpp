#include <map>
#include <set>
#include <string>
#include <iostream>

int main()
{
	std::set<int> set{ 1, 2, 3 };
	std::map<std::string, std::string> map{ {"mon", "월요일"}, {"tue", "화요일"} };

	// set/map 안에 특정 요소(2)가 있는지 알고 싶다.

	// C++20 이전
	auto ret = set.find(2);

	if (ret != set.end())
	{
		// 2가 set 안에 있는 경우.
	}

	// C++20 이후
	if (set.contains(2))
	{
	}
}
