#include <iostream>
#include <source_location>

int main()
{
	// C style => 매크로!
	std::cout << __FILE__ << std::endl; // 파일 이름
	std::cout << __func__ << std::endl;	// 현재 함수 이름
	std::cout << __LINE__ << std::endl; // line 

	// C++20 부터 위 매크로 사용하지 말고, 아래 처럼 하세요
	std::source_location loc = std::source_location::current();

	std::cout << loc.file_name()     << std::endl;
	std::cout << loc.function_name() << std::endl;
	std::cout << loc.line()			 << std::endl;

}
