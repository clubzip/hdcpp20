#include <iostream>

// attribute ���� 
// => C++11 ���� ���Ե� ����
// => [[ ]]  �� ǥ��
// => �����Ϸ����� �پ��� ���� �����ϴ� ����

// C++ �������� ��� �߰��ǰ� ����

// [[nodiscard]] : ��ȯ ���� �����ϴ� ��� ��� �߻��� �޶�
//					C++17
// 
// C++20 ���� 4�� �߰�
// [[nodiscard(msg)]] 
// [[likely]]
// [[unlikely]]
// [[no_unique_address]]

[[nodiscard("my message")]] int* allocate(int size)
{
	return new int[size];
}

int main()
{
	allocate(10);
}
