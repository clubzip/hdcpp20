#include <iostream>
#include <type_traits>

// �� ������ �ִ� ������� ���ϴ� �Լ��� ������ ���ô�.

template<typename T>
T gcd(T a, T b)
{
	static_assert(std::is_integral_v<T>, "error not integer");

	return 0; // a, b��  �ִ� ������� ���ߴٰ� ����
}

int main()
{
	gcd(10, 4);
	gcd(3.4, 4.2); 
}
