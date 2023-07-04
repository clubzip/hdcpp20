#include <iostream>
#include <type_traits>

// 두 정수의 최대 공약수를 구하는 함수를 생각해 봅시다.

template<typename T>
T gcd(T a, T b)
{
	static_assert(std::is_integral_v<T>, "error not integer");
	return 0; // a, b의  최대 공약수를 구했다고 가정
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

	gcd(3.4f, 4.2f); // 핵심.!!! 인자가 float 타입이라면!!
					 // => double 은 아니므로
					 // => template 사용.. 그런데, static_assert
					 //    때문에 실팽
}
