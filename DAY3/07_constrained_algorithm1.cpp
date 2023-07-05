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


	// python �� sort
	// => �񱳿� ����� �Լ��� �����Լ��� ����
	// => �Լ�(e1) < �Լ�(e2) �� ��!!
	// std::sort(v.begin(), v.end(),
	//	[](const std::string& s) { return s.size(); });


	// C++20 �� ����
	// => e1, e2 �� ���Ҷ�
	// => �����Լ�( �����Լ�(e1), �����Լ�(e2) )
	// => �̶� Ű������� �����Լ��� "projection" �̶�� �մϴ�.
	std::sort(v.begin(), v.end(), ���׺��Լ�, Ű���� ��� �����Լ�);


	for (const auto& e : v)
	{
		std::cout << e << ", ";
	}

}