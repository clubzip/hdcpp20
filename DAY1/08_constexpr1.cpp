#include <iostream>

// constexpr - C++11 ���� ����
// => �Լ� ���ڰ��� ������ �ð��� �˼� �ִٸ�
//    �Լ� ������ ������ �Ҷ� �Ҽ� �ִٴ� �ǹ�

constexpr auto add(int a, int b)
{
	bool ret = std::is_constant_evaluated(); // C++20 ���� �߰��� �Լ�

	// constexpr �Լ� �ȿ����� cout �� ����Ҽ��� �����ϴ�.

	return std::pair<int, bool>(a + b, ret);
}
/*
int main()
{
	int x = 1, y = 2;

	int arr1[add(1, 2)]; // ok. add ȣ���� ������ �Ҷ� ����. 
//	int arr2[add(x, y)]; // error. ���� ���� ������ �Ҷ� �˼� ����.
						 //        add() �Լ��� ������ �Ҷ� ���� �ȵ�.

	int ret1 = add(x, y);// ok. x, y �� ���� ����, add() ȣ���� ����ϴ�
						// ������ ������ �ð��� �䱸���� ����.
						// �׷���, add()�� ����ð��� ȣ��

	int ret2 = add(1, 2);  // ������ �ð� ? ����ð� ?
	

}
*/

int main()
{
	int x = 1, y = 2;

	auto ret1 = add(1, 2);
	std::cout << ret1.second << std::endl;


	auto ret2 = add(x, y);
	std::cout << ret2.second << std::endl;


	constexpr auto ret3 = add(1, 2);
	std::cout << ret3.second << std::endl;
}