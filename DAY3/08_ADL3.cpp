#include <iostream>
#include <string>
#include <algorithm>

int main()
{
	int n1 = 10;
	int n2 = 20;

	std::string s1 = "AAA";
	std::string s2 = "BBB";

	std::swap(n1, n2); // ok
	std::swap(s1, s2); // ok

	swap(n1, n2);	// error. swap 는 std:: 안에 있으므로..
	swap(s1, s2);	// ok     s1, s2 는 모두 std:: 안에 있는 타입이므로
					//		  자동검색 됩니다.

}