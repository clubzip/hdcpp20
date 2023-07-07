// C++20 : <format> 이 도입되었습니다.
// C++23 : <print>  이 도입되었습니다.

// std::cout  단점
// 1. 너무 느립니다.
// 2. 코드가 너무 장황합니다. 출력할 변수가 많으면 " << " 이 너무 많이 등장

// std::cout 의 대안으로 사용했던것들
// 1. C 언어 printf 계속 사용
// 2. fmt 라이브러리(오픈소스) - 아주 빠르게 출력,  std::print() 제공

// C++23 
// => fmt 라이브러리와 유사하게 새로운 표준 출력을 만들었습니다.
#include <print> // g++ 13.1 현재 지원 안됨
				 // visual studio 17.7(preview 버전) 부터 지원
				 // 오늘 현재 최신 버전 visual studio 17.6.4
#include <string>
#include <format>

int main()
{
	// 사용법은 "std::format" 과 동일합니다.
	// std::format : 인자의 내용대로 문자열 만들기
	std::string s = std::format("{0}, {1}", "kim", 20);

	// std::print : 인자의 내용대로 화면 출력
	std::print("{0}, {1}\n", "kim", 20);
	std::println("{0}, {1}", "kim", 20);
}
