#include <vector>
#include <iostream>

// �ٽ� 1. �Ʒ� ����� take_view, reverse_view ���� view �� 30���� �����˴ϴ�.
#include <ranges>

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	// �ٽ� 2. �پ��� view Ŭ������ 3���� ������� ���� �Ҽ� �ֽ��ϴ�.
	// => namespace �̸� �� ����� �μ���

	// ��� 1. Ŭ���� �̸� ���� ���
	std::ranges::take_view tv1(v, 5);


	// ��� 2. ���� �Լ� ���
	auto tv2 = std::views::take(v, 5);


	// ��� 3. pipe line ���
	auto tv3 = v | std::views::take(5);





	for (auto e : v)
		std::cout << e << ", ";

	std::cout << std::endl;



}