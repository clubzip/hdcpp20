// advance1
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>

int main()
{
	std::list<int>         s1 = { 1,2,3 }; // ���� ����Ʈ
	std::forward_list<int> s2 = { 1,2,3 }; // �̱� ����Ʈ

	auto p1 = s1.begin();
	auto p2 = s2.begin();

	// ������ ������ ã������ 
	++p1;
	--p1;
	++p2;
	--p2;
}