// advance1
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>
#include <iostream>

int main()
{
//	std::list<int>   c = { 1,2,3,4, 5, 6, 7 };
	std::vector<int> c = { 1,2,3,4, 5, 6, 7 };

	auto p = c.begin(); 

	// p�� 5ĭ �����Ϸ��� �մϴ�.
	// => �ּ��� ������ ??


	std::cout << *p << std::endl; // 6
	

}
