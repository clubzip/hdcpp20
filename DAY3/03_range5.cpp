#include <vector>
#include <iostream>
#include <ranges>

// nested..

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	// �ٽ� 1. ��ø �����մϴ�. !!! �߿�!!!

	// ��� 1. Ŭ���� �̸� ���� ���
	std::ranges::take_view tv(v, 5);
	std::ranges::filter_view fv(tv, [](int n) { return n % 2 == 0; });
	std::ranges::reverse_view rv(fv);




	// ��� 2. �Լ� ����
	auto rv2 = std::views::reverse(std::views::filter(
							std::views::take(v, 5),
								[](int n) { return n % 2 == 0; }));

	// ��� 3. pipe line ���� 
	// => ���� reverse_view �� pipe line ������ �Լ��� �ƴ� std::views::reverse
	auto rv3 = v | std::views::take(5)
				 | std::views::filter([](int n) { return n % 2 == 0; })
				 | std::views::reverse;
	
//	for (auto e : rv2)  // 4, 2
	for (auto e : v | std::views::take(5) | std::views::reverse ) 
	{
		std::cout << e << ", ";
	}
	std::cout << std::endl;
}