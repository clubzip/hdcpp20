#include <iostream>
#include <vector>
#include <list>
#include <iterator>

// ������ ���� ���ϴ� sum �� ����� ���ô�.

template<typename T>
? sum(T first, T last)
{
	? s = 0;

	while (first != last)
	{
		s += *first;
		++first;
	}
	return s;
}


int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	int s = sum(v.begin(), v.end());

	std::cout << s << std::endl; // 55
}










