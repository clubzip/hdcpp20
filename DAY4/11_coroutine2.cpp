#include <iostream>
#include <coroutine>

// Step 2. �Լ��� coroutine ���� �������
// 
// => �Լ� �ȿ��� "co_await", "co_yield", "co_return" �� �Ѱ��� Ű���带
//    ����ϸ� coroutine �� �˴ϴ�

// �Ʒ� �ڵ�� ���� �Դϴ�.
// => coroutine �� ���Ѿ� �ϴ� ��Ģ�� �ִµ�.
// => ��Ģ�� ��Ű�� �ʾҽ��ϴ�.

void foo()
{
	std::cout << "foo 1" << std::endl;

	co_await std::suspend_always{};

	std::cout << "foo 2" << std::endl;
}


int main()
{
	foo();
}
