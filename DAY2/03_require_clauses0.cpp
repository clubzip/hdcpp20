#include <iostream>

// ���� ) ���� �̸��� �Ϲ��Լ��� �Լ� ���ø��� ������ ��Ģ
template<typename T> 
void foo(T a)   { std::cout << "T" << std::endl; }

// void foo(int a) { std::cout << "int" << std::endl; }

int main()
{
	foo(3); // 1. int ���. exactly matching 
			// 2. int ������ ������ ���ø� ���
}