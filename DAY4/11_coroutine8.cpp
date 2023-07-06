#include <iostream>
#include <coroutine>
#define log() std::cout << "==============> " << __func__ << std::endl 


// Step 7. co_yield

// co_await : ������ ���߰�(suspend) ȣ���ڿ� ���ư���
// co_yield : ""					""	          ����ȯ!

class Generator
{
public:
	class promise
	{
		int value;
	public:
		int get_value() const { return value; }

		std::suspend_always yield_value(int n)
		{
			value = n;
			log();
			return {};
		}

		std::suspend_always initial_suspend()
		{
			log();
			return {};
		}
		std::suspend_always final_suspend() noexcept { log();  return {}; }

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

//private:
public:
	std::coroutine_handle<promise_type> coro_handle;
};


Generator foo()
{
	//--------------------------
	// �����Ϸ��� ������ �ڵ尡 ����ǰ�
	// ���⼭ main ���� ���ư�..
	//--------------------------
	std::cout << "foo 1" << std::endl;

//	co_await std::suspend_always{};

	co_yield 10;	// �� �ڵ�� �Ʒ� �ڵ�� �����ϴ�.
					// co_await promise_type��ü.yield_value(10)
					
					// 1. promise_type �� yield_value �־�� �մϴ�.
					// 2. yield_value �� std::suspend_always ��ȯ�ؾ� �մϴ�.
	
	std::cout << "foo 2" << std::endl;
	
	co_yield 20;
}

int main()
{
	Generator g = foo();
	std::cout << "main 1" << std::endl;

	g(); // co_yield �� ��ȯ�� ���� �ᱹ
		 // promise��ü.get_value() �ϸ� �˴ϴ�.

	int ret = g.coro_handle.promise().get_value();
	std::cout << ret << std::endl;

	std::cout << "main 2" << std::endl;

	g();

	std::cout << "main 3" << std::endl;

}
