#include <iostream>
#include <source_location>

int main()
{
	// C style => 매크로!
	std::cout << __FILE__ << std::endl; // 파일 이름
	std::cout << __func__ << std::endl;	// 현재 함수 이름 - main
	std::cout << __LINE__ << std::endl; // line 

	// C++20 부터 위 매크로 사용하지 말고, 아래 처럼 하세요
	std::source_location loc = std::source_location::current();

	// 아래 처럼 만들어도 에러는 아니지만, 유효하지 않은 값을 가지게 됩니다.
	// 꼭 위처럼 초기화 해서 사용하세요
//	std::source_location loc2;

	std::cout << loc.file_name()     << std::endl;
	std::cout << loc.function_name() << std::endl;
				// => "main" 만 나올수도 있고
				// => "int main(void)" 등으로 signature를 포함할수도 있습니다.
				// => C++ 표준문서에는 "구현에 따라 다를수 있음" 이라고 되어 있습니다.

	std::cout << loc.line()			 << std::endl;

}
