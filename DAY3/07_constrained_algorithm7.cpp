#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// C++20 에서는 기존에 있던 대부분의 알고리즘을 다시 만들었습니다.
// => std::ranges 안에 있습니다.

int main()
{
	std::vector<std::string> v = { "banana", "apple", "pear", "orange" };

	// 핵심 1. 반복자 버전 vs 컨테이너 버전
//	std::ranges::sort(v.begin(), v.end()); // 반복자 버전
//	std::ranges::sort(v);				   // 컨테이너 버전

	// 핵심 2. 비교 함수 교체 - C++98 과 유사
//	std::ranges::sort(v);  // 기본 버전 : std::less 사용 , < 로 비교
//	std::ranges::sort(v, [](auto& s1, auto& s2) { return s1 > s2; });

//	std::ranges::sort(v, std::greater{} ); // 위와 동일, > 연산을 하는 함수객체


	// 핵심 3. projection 사용

//	std::ranges::sort(v, std::less{}, &std::string::size );  // less는 < 연산
//	std::ranges::sort(v, {}, &std::string::size);  // {} 만 전달해도 됨.
											// 디폴트 타입이 less로 지정되었으므로

	std::ranges::sort(v, std::greater{}, &std::string::size);


	for (const auto& e : v)
	{
		std::cout << e << ", ";
	}

}