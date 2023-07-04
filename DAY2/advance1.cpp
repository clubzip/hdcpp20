// advance1
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>

int main()
{
	std::list<int>         s1 = { 1,2,3 }; // 더블 리스트
	std::forward_list<int> s2 = { 1,2,3 }; // 싱글 리스트

	auto p1 = s1.begin();
	auto p2 = s2.begin();

	// 다음중 에러를 찾으세요 
	++p1;
	--p1;
	++p2;
	--p2;
}