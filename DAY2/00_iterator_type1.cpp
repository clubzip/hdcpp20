#include <iostream>
#include <vector>
#include <list>
#include <iterator>

// 구간의 합을 구하는 sum 을 만들어 봅시다.

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










