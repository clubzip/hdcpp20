#include <iostream>

// ��� ���� : cl math.ixx /c  /std:c++20
// ��� ��� : cl 1_module1.cpp  mymath.obj  /std:c++20

import mymath;

int main()
{
	int n = add(1, 2);

	std::cout << n << std::endl;

	Point p(1, 2);
	p.print();
}

