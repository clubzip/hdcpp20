#include <iostream>
#include <coroutine>
#define log() std::cout << __func__ << std::endl 


// Step 5. �ڷ�ƾ �ڵ��̾߱�
// => ȣ����(main) �� �ڷ�ƾ�� �ڵ��� �˾ƾ� �ڷ�ƾ�� �����Ҽ� �ֽ��ϴ�.
// => ȣ����(main) �� ��ԵǴ� ���� �ᱹ Generator ��ü �Դϴ�.

// Generator �� ���� : �ڷ�ƾ�� ��ȯ ��
//					  => ��κ� �ڷ�ƾ�� �ڵ��� ����� ������ �˴ϴ�.

// promise_type �� ��Ȱ : �ڷ�ƾ ������ �߻��ϴ� �پ��� �̺�Ʈ�� ����
//						 ���� ��� �ϱ� ���� Ŭ����
//						 => 1��° suspend, final suspend
//						 => ���� ó��, ��ȯ�� ó��



class Generator
{
public:
	class promise
	{
	public:
		std::suspend_always initial_suspend()
		{
			log();
			return {};
		}
		std::suspend_always final_suspend() noexcept { log();  return {}; }
		Generator get_return_object() { log(); return {}; };
		void unhandled_exception() { log(); }
		void return_void() { log(); }
	};
	//--------------------------------------------------------
	// Generator ��� ��
	using promise_type = promise;

	std::coroutine_handle<promise_type> coro_handle; // �������Ÿ

	Generator(std::coroutine_handle<promise_type> h)
		:coro_handle(h)
	{
	}

};





Generator foo()
{
	//--------------------------
	// �����Ϸ��� ������ �ڵ尡 ����ǰ�
	// ���⼭ main ���� ���ư�..
	//--------------------------
	std::cout << "foo 1" << std::endl;

	co_await std::suspend_always{};

	std::cout << "foo 2" << std::endl;
}

int main()
{
	Generator g = foo();
}
