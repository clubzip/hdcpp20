#include <functional>
#include <iostream>
using namespace std::placeholders;

void foo(int a, int b)
{
	std::cout << a << ", " << b << std::endl;
}

int main()
{
	// C++11 bind
	// => ���� �Լ��� ���ڸ� Ư���� ������ ������ ���ο� �Լ��� ����� ����
	
	// ���ڰ� 2���� �Լ�(foo) �� 1��° ���ڸ� ������ ���ο� �Լ��� ����� �ڵ�
	auto f1 = std::bind(&foo, 0, _1);
	f1(20); // foo(0, 20) ���� ȣ��..


	// C++20 bind_front : 1���� ���ڸ� ������ �Լ� �����.

}
