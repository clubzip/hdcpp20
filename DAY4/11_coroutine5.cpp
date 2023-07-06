#include <iostream>
#include <coroutine>

// C++ �ڷ�ƾ�� ��� �����ϴ°� ?
// ������ ���캸�� �ڵ�..
// �ּ��� �� �����غ�����..

class Generator
{
public:

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
	// �Լ� �ȿ� "co_await" ���� Ű���尡 ������ �����Ϸ��� �Ʒ� �ڵ带 �����մϴ�.
	//---------------------------------------------
	// 1. �ڷ�ƾ frame �� ���� �����մϴ�.
	// => sizeof(��������) + sizeof(��ȯŸ��::promise_type) + ��Ÿ ���� 
	//		 => ���������� ��� 200 ~ 400 byte ���� �����Ϸ����� �ٸ��ϴ�.

	// 2. promise_type �� ������ ȣ��

	// 3. promise_type �� get_return_objec()�� ȣ���ؼ� Generator ����

	// 4. promise_type �� initial_update() ȣ��

	// 5. (3) ���� ������ ��ü�� ��ȯ.. 
	//    => ��, ���⼭ main ���� ��ȯ




	//---------------------------------------------
	std::cout << "foo 1" << std::endl;

	co_await std::suspend_always{};

	std::cout << "foo 2" << std::endl;
}



int main()
{
	foo();
}
