#include <iostream>
#include <type_traits>

// 두 정수의 최대 공약수를 구하는 함수를 생각해 봅시다.

template<typename T>
T gcd(T a, T b)
{
	static_assert(std::is_integral_v<T>, "error not integer");

	return 0; // a, b의  최대 공약수를 구했다고 가정
}

int main()
{
	gcd(10, 4);
	gcd(3.4, 4.2); 
}
