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

	swap(n1, n2);	// error. swap �� std:: �ȿ� �����Ƿ�..
	swap(s1, s2);	// ok     s1, s2 �� ��� std:: �ȿ� �ִ� Ÿ���̹Ƿ�
					//		  �ڵ��˻� �˴ϴ�.

}