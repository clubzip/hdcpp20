#include <iostream>
#include <string_view>
#include <source_location>


void f(std::source_location loc = std::source_location::current())
{
	// line �� �ƴ϶� column �� �ֽ��ϴ�.

	std::cout << loc.line() << std::endl;
	std::cout << loc.column() << std::endl;
}
int main()
{
//34567890
	f();
f();
}




