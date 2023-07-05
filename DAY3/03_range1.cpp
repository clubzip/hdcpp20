#include <vector>
#include <iostream>

// �ٽ� : range-for �� ����

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	// C++11 �� range-for
	// => ����� ��� �Ҽ� ������ ?
	// => �Ϻθ� ����Ҽ� ������ ?
	// ==> C++20 �� range library �� ����ϸ� �˴ϴ�.
	for (auto e : v)
		std::cout << e << ", ";

	std::cout << std::endl;

	// �ٽ� 1. range-for �� ������ ���� �ؾ� �մϴ�.
	// => �� for ���� �����Ϸ��� �Ʒ� ó�� �����մϴ�.

	auto first = std::begin(v);
	auto last  = std::end(v);

	for (; first != last; ++first)
	{
		auto e = *first;
		//------------------------
		std::cout << e << ", ";
	}

}