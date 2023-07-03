#include <iostream>
#include <string_view>
#include <source_location>


void f(std::source_location loc = std::source_location::current())
{
	// line 뿐 아니라 column 도 있습니다.

	std::cout << loc.line() << std::endl;
	std::cout << loc.column() << std::endl;
}
int main()
{
//34567890
	f();
f();
}




