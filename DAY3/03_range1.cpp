#include <vector>
#include <iostream>

// 핵심 : range-for 의 원리

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	// C++11 의 range-for
	// => 뒤집어서 출력 할수 없나요 ?
	// => 일부만 출력할수 없나요 ?
	// ==> C++20 의 range library 를 사용하면 됩니다.
	for (auto e : v)
		std::cout << e << ", ";

	std::cout << std::endl;

	// 핵심 1. range-for 의 원리를 이해 해야 합니다.
	// => 위 for 문을 컴파일러가 아래 처럼 변경합니다.

	auto first = std::begin(v);
	auto last  = std::end(v);

	for (; first != last; ++first)
	{
		auto e = *first;
		//------------------------
		std::cout << e << ", ";
	}

}