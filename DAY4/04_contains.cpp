#include <map>
#include <set>
#include <string>
#include <iostream>

int main()
{
	std::set<int> set{ 1, 2, 3 };
	std::map<std::string, std::string> map{ {"mon", "������"}, {"tue", "ȭ����"} };

	// set/map �ȿ� Ư�� ���(2)�� �ִ��� �˰� �ʹ�.

	// C++20 ����
	auto ret = set.find(2);

	if (ret != set.end())
	{
		// 2�� set �ȿ� �ִ� ���.
	}

	// C++20 ����
	if (set.contains(2))
	{
	}
}
