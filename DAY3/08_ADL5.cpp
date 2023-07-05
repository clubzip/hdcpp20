#include <iostream>
#include <ranges>
#include <vector>
#include <algorithm>

int main()
{
	std::vector v = { 1,2,3,4,5 };

	// C++98 �˰��� : ��� �Լ�(���ø�) �Դϴ�.
	auto ret1 = std::find(v.begin(), v.end(), 3);

	// C++20 �˰��� : ��� �Լ���ü �Դϴ�.
	auto ret2 = std::ranges::find(v, 3);
	auto ret3 = std::ranges::find.operator()(v, 3);
}