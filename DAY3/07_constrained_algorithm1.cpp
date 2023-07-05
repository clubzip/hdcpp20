#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
	std::vector<std::string> v = { "banana", "apple", "pear", "orange"};

	// 기본 모양 : 문자열 끼리 크기 비교해서 오름 차순으로 정렬
	// < 로 비교.
	//std::sort(v.begin(), v.end());


	// 요구사항 : 문자열을 사전순서가 아닌 문자열 길이 순서로 정렬하고 싶다.
	
	// C++98 : 3번째 인자로 비교정책을 담은 이항 함수 전달
	std::sort(v.begin(), v.end(),
		[](const std::string& s1, const std::string& s2) 
					{ return s1.size() < s2.size(); });


	// python 의 sort
	// => 비교에 사용할 함수를 단항함수로 제공
	// => 함수(e1) < 함수(e2) 로 비교!!
	// std::sort(v.begin(), v.end(),
	//	[](const std::string& s) { return s.size(); });


	// C++20 의 선택
	// => e1, e2 를 비교할때
	// => 이항함수( 단항함수(e1), 단항함수(e2) )
	// => 이때 키값을얻는 단항함수를 "projection" 이라고 합니다.
	std::sort(v.begin(), v.end(), 이항비교함수, 키값을 얻는 단항함수);


	for (const auto& e : v)
	{
		std::cout << e << ", ";
	}

}