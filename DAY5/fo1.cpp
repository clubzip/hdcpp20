// fo1.cpp
#include <iostream>
#include <vector>
#include <algorithm>

bool foo(int n)
{
	return n % 3 == 0;
}

int main()
{
	std::vector v = { 1,6,3,7,8 };

	// 1. �־��� �������� 3�� ã�� �ʹ�.
	auto ret1 = std::find(v.begin(), v.end(), 3);

	// 2. �־��� �������� "3�� ���" �� ã�� �ʹ�.
	auto ret2 = std::find_if(v.begin(), v.end(), foo);


	// 3. �־��� �������� "k�� ���" �� ã�� �ʹ�.

	int k = 3; // ����ڰ� �Է��� ���̶�� ������ ������ 

	auto ret3 = std::find_if(v.begin(), v.end(), ? );
}