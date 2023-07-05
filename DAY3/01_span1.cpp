#include <iostream>
#include <string>
#include <string_view>	// C++17






// C++17 의 string_view 이야기. 
int main()
{
	std::string src = "to be or not to be";

	// 핵심 1. string vs string_view
	// string : 자원(문자열)을 소유
	// string_view : 자원을 빌려서(borrowed) 사용
	std::string      ss1 = src; // 깊은 복사로 구현
								// 문자열을 가진 메모리 자체가 복사

	std::string_view sv1 = src; // 포인터 한개 + 문자열 길이 정보만 보관
								// sv1 의 포인터가 src 의 버퍼를 가리키게 된다.
	//-------------------------------------------------------------------
	// 핵심 2. string_view 로는 읽기만 가능합니다.
//	sv1[0] = 'c';    // error
	auto c = sv1[0]; // ok


	// 핵심 3. string_view 를 문자열 literal로 초기화 하는 경우
	// ==> 이부분이 핵심 입니다. "정확히 이해해 두세요"
	const char* p = "to be or not to be"; // C언어의 문자열 포인터

	std::string      ss2 = "to be or not to be";
						// => 힙을 할당해서 문자열 자체를 복사합니다.
						// => ss2 가 문자열을 소유

	std::string_view sv2 = "to be or not to be";
						// => 상수 메모리에 있는 문자열을 그냥 가리킵니다.
						// => C 언어의 문자열 포인터와 같은 개념
						// => const char* 

	// 핵심 4
	std::string_view sv3 = src; // sv3 이 src 의 문자열을 빌려서 사용
	std::string_view sv4 = "to be or not to be"; // 상수 메모리의 문자열
											// 을 가리키는 포인터의미
}








