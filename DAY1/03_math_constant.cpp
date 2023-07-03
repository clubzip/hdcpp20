#include <numbers>  // 다양한 수학 상수 값들..(C++20)
#include <iostream>

// "std::numbers" 라는 이름 공간안에 있습니다.

int main()
{
	std::cout << std::numbers::pi << std::endl;		// 3.14159
	std::cout << std::numbers::e << std::endl;		// 2.71828
	std::cout << std::numbers::sqrt2 << std::endl;	// 1.41421
}

