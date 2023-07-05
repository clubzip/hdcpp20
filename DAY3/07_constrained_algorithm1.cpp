#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
	std::vector<std::string> v = { "banana", "apple", "pear", "orange"};

	// �⺻ ��� : ���ڿ� ���� ũ�� ���ؼ� ���� �������� ����
	// < �� ��.
	//std::sort(v.begin(), v.end());


	// �䱸���� : ���ڿ��� ���������� �ƴ� ���ڿ� ���� ������ �����ϰ� �ʹ�.
	
	// C++98 : 3��° ���ڷ� ����å�� ���� ���� �Լ� ����
	std::sort(v.begin(), v.end(),
		[](const std::string& s1, const std::string& s2) 
					{ return s1.size() < s2.size(); });

	for (const auto& e : v)
	{
		std::cout << e << ", ";
	}

}