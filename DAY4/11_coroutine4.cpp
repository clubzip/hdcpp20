#include <iostream>
#include <coroutine>


// Step 4. promise_type �� ����
// => ����� ���� Ŭ������ ���� �ϰ�
// => ��ӵ� 5���� �Լ��� �����. 
// => Generator �ȿ��� "promise_type" �̶�� �̸����� ����


class Generator
{
public:
	// promise ��� �Լ� �ȿ��� Generator Ŭ���� �̸��� ����ϰ� �˴ϴ�.
	// => �׷��� ���� nested �� ���� �մϴ�.
	// => �ݵ�� nested �� �ؾ� �ϴ� ���� �ƴմϴ�
	// => ���漱������� �ذ��ص� �˴ϴ�.
	class promise
	{
	public:
		std::suspend_always initial_suspend() { return {}; }
		std::suspend_always final_suspend() noexcept { return {}; }
		Generator get_return_object() { return {}; };
		void unhandled_exception() {}
		void return_void() {}
	};

	using promise_type = promise;
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
