#include <iostream>
#include <coroutine>
#define log() std::cout << "==============> " << __func__ << std::endl 


// Step 6. �ణ�� �ڵ� ����
// => coroutine �ڵ��� ���� �������� ����
// => operator() �����ڷ�.. ����


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

		// �ڷ�ƾ�� ���۵ɶ� �����Ϸ��� �߰��� �ڵ尡
		// Generator �� ����� ���� �Ʒ� �Լ� ȣ��
		Generator get_return_object()
		{
			auto h = std::coroutine_handle<promise_type>::
				from_promise(*this);
			log();
			return Generator(h);
		};

		void unhandled_exception() { log(); }
		void return_void() { log(); }
	};
	//--------------------------------------------------------
	// Generator ��� ��
	using promise_type = promise;


	Generator(std::coroutine_handle<promise_type> h)
		:coro_handle(h)
	{
	}
	~Generator()
	{
		if (coro_handle)
			coro_handle.destroy();
	}

	void operator()()
	{
		if (coro_handle && !coro_handle.done())
		{
			coro_handle.resume();
		}
	}

private:
	std::coroutine_handle<promise_type> coro_handle;
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
	std::cout << "main 1" << std::endl;
	
	g();

	std::cout << "main 2" << std::endl;
	
	g();

	std::cout << "main 3" << std::endl;

}
