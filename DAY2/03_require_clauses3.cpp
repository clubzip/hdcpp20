#include <iostream>
#include <type_traits>

// C++11 시절에는 "enable_if" 라는 테크닉으로 할수 있습니다.
/*
template<typename T> 
std::enable_if_t< std::is_integral_v<T>, T>
gcd(T a, T b)
{
	return 0;
}
*/
// 하지만 C++20 이 훨씬 간결하고
// => 테크닉이 아닌 문법이므로 훨씬 안전합니다.

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
