#include <iostream>
#include <coroutine>

// Generator �� "promise_type" �� ������ ����
// => 'promise_type': 'std::coroutine_traits<Generator>'�� ����� �ƴմϴ�.

// Generator �� "promise_type" �� ������ �����޼����� ����˴ϴ�.

// Step 3. �ڷ�ƾ�� ��Ģ
// => �ݵ�� "promise_type" �̶�� ��� Ÿ���� �ִ� Ÿ���� ��ȯ�ؾ� �Ѵ�.

// ��� : �ڷ�ƾ�� ��ȯ Ÿ����
// => ����� ���� Ÿ��(Ŭ����)�� �����ϰ�
// => "promise_type" �̶�� Ÿ���� ����� ��������.


class Generator
{
public:
	using promise_type = int;
};

Generator foo()
{
	std::cout << "foo 1" << std::endl;

	co_await std::suspend_always{};

	std::cout << "foo 2" << std::endl;
}


int main()
{
	foo();
}
