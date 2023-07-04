#include <iostream>
#include <type_traits>

// C++11 �������� "enable_if" ��� ��ũ������ �Ҽ� �ֽ��ϴ�.
/*
template<typename T> 
std::enable_if_t< std::is_integral_v<T>, T>
gcd(T a, T b)
{
	return 0;
}
*/
// ������ C++20 �� �ξ� �����ϰ�
// => ��ũ���� �ƴ� �����̹Ƿ� �ξ� �����մϴ�.

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
