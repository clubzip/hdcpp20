#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

// ������ ����

int main()
{
	std::vector v = { 1,2,3,4,5,6,7,8,9,10 };

	// fv �� ����������
	// => v�� ������ �����ϰ�, filter �� ������ �Լ��� ������ �մϴ�.
	// => ���� �Լ��� ����Ǵ� ������ "����" �Ҷ� �Դϴ�.
	// => ��, fv ��ü�� ��Ҹ� �����ϴ� ���� �ƴմϴ�.
	auto fv = v | std::views::filter([](int n) { return n % 2 == 0; });
	
//	std::ranges::filter_view fv(v, [](int n) { return n % 2 == 0; });

	// fv �� ������ �Ŀ� v �� ����
	v[1] = 20;
	v[3] = 40;
	v[5] = 60;

	// v ����� ���� fv �� ���� filter ����
	for (auto e : fv) //  20, 40, 60, 8, 10
	{
		std::cout << e << ",  ";
	}
	std::cout << std::endl;
}
// C# �� ���� ������ ����� �ֽ��ϴ�. 
// LINQ ��� �մϴ� Language INtegrated Query
// C++ : v | filter( �Լ� )
// C#  : v.select( �Լ� ).order(����) ó�� ���� �� ���� ���

