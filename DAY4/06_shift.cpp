#include <iostream>
#include <vector>
#include <algorithm>

template<typename T> void show(T& c)
{
	for (auto n : c) 
		std::cout << n << ", ";
	std::cout << std::endl;
}

int main()
{
	std::vector<int> v1 = { 1,2,3,4,5,6,7,8,9,10 };

	show(v1);

	// C++20 ���� �߰��� �˰���.
	// => C ����� >> << ������ �����̳ʿ� ���ؼ� �����ϴ� ��
	std::shift_left(std::begin(v1), std::end(v1), 3);
	show(v1); // 4,5,6,7,8,9,10, 8, 9, 10

	std::shift_right(std::begin(v1), std::end(v1), 3);
	show(v1); // 4,5,6,4,5,6,7,8,9,10
}
