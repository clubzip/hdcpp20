#include <iostream>
#include <algorithm>
#include <vector>
#include <ranges>

int main()
{
	std::vector v = { 1,2,3,4,5 };
//	int v[] = { 1,2,3,4,5 };

	// �ݺ��ڸ� ��� ���
	// 1. C++98
	// => ���� : v �� raw array �� ���� ����!
	auto p1 = v.begin();		


	// 2. C++11 : ����� �ƴ� �Ϲ��Լ� begin ����
	// => v �� raw array �� ok.
	auto p2 = std::begin(v);	

	auto sz1 = v.size();     // v �� raw array ��� ����
	auto sz2 = std::size(v); // v �� raw array �� ok. 
	


	// 3. C++20 ���� "���ο� begin()" �� �߰��Ǿ����ϴ�.
	// std::ranges : namespace �̸�. std �ȿ� ranges ��� �̸� ����
	// namespace std
	// {
	//		namespace ranges {    }
	// }
	auto p3 = std::ranges::begin(v);
}