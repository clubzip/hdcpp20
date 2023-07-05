#include <iostream>
#include <vector>

// C++20 �� ranges ���̺귯�� �ȿ���
#include <ranges>

int main()
{
	std::vector v = { 1,2,3,4,5 };

	// 1. �پ��� view �� �ֽ��ϴ�. ���� "range adaptor" ��� �θ��ϴ�.
	std::ranges::take_view tv(v, 5);


	// 2. range �� �پ��� Ư���� �����ϴ� concept �� �ֽ��ϴ�.
	bool b1 = std::ranges::range<std::vector<int>>; // true
	bool b2 = std::ranges::borrowed_range<std::vector<int>>; // false
	

	// 3. �پ��� �Լ��� �ֽ��ϴ�.
	auto p1 = std::ranges::size(tv);


	// 4. �پ��� Ÿ�� ��ƿ��Ƽ�� �ֽ��ϴ�.
	std::ranges::range_value_t< std::vector<int>> n; // int
}