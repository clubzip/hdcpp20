#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// C++20 ������ ������ �ִ� ��κ��� �˰����� �ٽ� ��������ϴ�.
// => std::ranges �ȿ� �ֽ��ϴ�.

int main()
{
	std::vector<std::string> v = { "banana", "apple", "pear", "orange" };

	// �ٽ� 1. �ݺ��� ���� vs �����̳� ����
	std::ranges::sort(v.begin(), v.end()); // �ݺ��� ����
	std::ranges::sort(v);				   // �����̳� ����



	for (const auto& e : v)
	{
		std::cout << e << ", ";
	}

}