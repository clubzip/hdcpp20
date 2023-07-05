#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
	std::vector<std::string> v = { "banana", "apple", "pear", "orange"};

	// 기본 모양 : 문자열 끼리 크기 비교해서 오름 차순으로 정렬
	std::sort(v.begin(), v.end());

	// 요구사항 : 문자열을 사전순서가 아닌 문자열 길이 순서로 정렬하고 싶다.


}