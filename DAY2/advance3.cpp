// advance1
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>
#include <iostream>

int main()
{
	std::list<int>   c = { 1,2,3,4, 5, 6, 7 };
//	std::vector<int> c = { 1,2,3,4, 5, 6, 7 };

	auto p = c.begin(); 

	// p�� 5ĭ �����Ϸ��� �մϴ�.
	// => �ּ��� ������ ??
//	p = p + 5; // ���� ��������, �������� �ݺ���(vector �ݺ���)�� ����

//	++p; ++p; ++p; ++p; ++p; // ��� �ݺ��ڿ� ��밡��������
							 // �������� �ݺ��ڶ�� �����ϴ�.

	// �ּ��� �ڵ�� �Ʒ� ��� �Դϴ�.
	std::advance(p, 5);

	std::cout << *p << std::endl; // 6
	

}
