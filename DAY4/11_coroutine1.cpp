#include <iostream>

// subroutine : �Ϲ� �Լ��� ȣ��,  call, return ����
// coroutine  : call, return �ܿ�, suspend, resume, destroy ������ ����

// coroutine �� �ٽ� : ���������� �����ϴ� stack �� ��� �����Ұ��ΰ� ?
// coroutine �� 2���� ����

// 1. stackful coroutine : ���������� stack �� �����ϴ� ���
// 2. stackless coroutine : ���������� stack �� �ƴ�
//							��� ����.

// C++�� "stackless" �Դϴ�.
// => coroutine �� ���������� ���� ���̰� �˴ϴ�.


// C#, Python, java, Go ���� ���
// => coroutine ����� �����ϴ�.
// => return ��� yield ���ϸ� �˴ϴ�.

// C++ coroutine
// => ����� �����մϴ�.
// => C++20 ���� Framework �� �����,, 
//    ���̺귯�� ������ C++23 ���� �̷�� �Ǿ����ϴ�.


// Step 1. �Ϲ� �Լ�
void foo()
{
	std::cout << "foo 1" << std::endl;
	std::cout << "foo 2" << std::endl;
}

int main()
{
	foo();
}
