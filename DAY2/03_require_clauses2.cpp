#include <iostream>
#include <type_traits>


// template �ȿ��� static_assert �� ����ϸ�
// => ������ �������� ������ ���� �߻�!!

// C++20. require clauses �� ����� ���ø�
// => ������ �������� ������ ������� �ʰڴ�!!
// => ���� �̸��� �ٸ� �Լ��� �ִٸ� ��밡��

// ��� ���� �ϼ���
// concept  ���鶧 requires : require expression(ǥ����)
// template ���鶧 requires : require clauses(��)

// requires �ڿ��� - traits, concept ���� ��� �ü� �ֽ��ϴ�.

template<typename T> requires std::is_integral_v<T>
T gcd(T a, T b)
{
	return 0;
}

double gcd(double a, double b)
{
	std::cout << "double" << std::endl;
	return 0;
}

int main()
{
	gcd(10, 4);
	gcd(3.4, 4.2);

	gcd(3.4f, 4.2f); 
}
