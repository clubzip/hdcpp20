#include <iostream>
#include <type_traits>

// �� ������ �ִ� ������� ���ϴ� �Լ��� ������ ���ô�.

template<typename T>
T gcd(T a, T b)
{
	static_assert(std::is_integral_v<T>, "error not integer");
	return 0; // a, b��  �ִ� ������� ���ߴٰ� ����
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

	gcd(3.4f, 4.2f); // �ٽ�.!!! ���ڰ� float Ÿ���̶��!!
					 // => double �� �ƴϹǷ�
					 // => template ���.. �׷���, static_assert
					 //    ������ ����
}
