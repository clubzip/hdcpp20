#include <iostream>
#include <vector>

int foo() { return 10; }

int main()
{
	std::vector v1{ 1,2,3 };

	// legacy "for"  in C++98
	for (std::size_t i = 0; i < v1.size(); i++)
	{
		std::cout << v1[i] << ", ";
	}

	// "range-based for" in C++11 
	for (auto& e : v1 )
	{
		std::cout << e << ", ";
	}

	// C++17 : init �� ���� ���
	if (int i = foo() ; i == 10)
	{

	}

	// C++20 : init �� ���� range - for ����
	for (std::vector v{ 1,2,3,4 }; auto e : v)
	{

	}
}
