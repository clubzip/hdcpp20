#include <iostream>

// C++20 ���� ���� ǥ������ ���� ���� �˴ϴ�.

int main()
{
	// add1 : int Ÿ�� 2���� �޴� ���� ǥ����
	auto add1 = [](int a, int b) { return a + b; };

	std::cout << add1(1, 2)     << std::endl;
	std::cout << add1(3.4, 4.2) << std::endl; // ������ �ƴ����� ����� 7


	// C++14�� generic lambda : ���� ǥ���� ���ڷ� auto ��밡��
	auto add2 = [](auto a, auto b) { return a + b; };

	std::cout << add2(1, 2)     << std::endl; // 3
	std::cout << add2(3.4, 4.2) << std::endl; // 7.6
	std::cout << add2(3,   4.2) << std::endl; // 7.2
	std::cout << add2(3.4, 4)   << std::endl; // 7.4
}
// C++14 generic lambda �� ����
// => �ٽ� 2���� ���ڰ� ���� �ٸ� ���ø�
class CompilerGeneratedName
{
public:
	template<typename T1, typename T2>
	auto operator()(T1 a, T2 b) const
	{
		return a + b;
	}
};
