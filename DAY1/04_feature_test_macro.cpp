#include <iostream>
#include <numbers>
#include <span>

// 현재 사용하는 컴파일러가 특정 문법을 지원하는 지 
// 확인 하는 방법.
// => 각 문법 지원 여부를 확인하는 매크로 제공
int main()
{
#ifdef __cpp_concepts
	std::cout << "support concepts" << std::endl;
#endif

#ifdef __cpp_modules
	std::cout << "support module" << std::endl;
#endif

	// 라이브러리 지원 여부
#ifdef __cpp_lib_span
	std::cout << "support span library" << std::endl;
#endif
}
// cppreferece.com 에서 "Feature Test Macro" 참고