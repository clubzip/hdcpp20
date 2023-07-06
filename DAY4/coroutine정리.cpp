#include <iostream>
#include <coroutine>
#include <thread>
#define log() std::cout << "==============> " << __func__ << std::endl 



template<typename T>
class Generator
{
public:
	class promise
	{
		T value;
	public:
		T get_value() const { return value; }

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

	T operator()()
	{
		if (coro_handle && !coro_handle.done())
		{
			coro_handle.resume();
			T ret = coro_handle.promise().get_value();

			return ret;
		}
		return 0;
	}

	Generator() = default;

	Generator(const Generator&) = delete;
	Generator& operator=(const Generator&) = delete;

	Generator(Generator&& other) : coro_handle(other.coro_handle)
	{
		other.coro_handle = {};
	}
	Generator& operator=(Generator&& other)
	{
		if (this == &other) return *this;

		if (coro_handle)
			coro_handle.destroy();

		coro_handle = other.coro_handle;
		other.coro_handle = {};

		return *this;
	}






private:
	std::coroutine_handle<promise_type> coro_handle;
};

//-----------------------------------

struct myawait
{
	bool await_ready() const noexcept { log(); return false; }

	void await_suspend(std::coroutine_handle<> handle) const noexcept
	{
		log();
	}
	void await_resume() const noexcept { log(); }
};


Generator<int> foo()
{
	// �����Ϸ��� �߰��� �ڵ�
	//---------------------------------------
	// 1. �ڷ�ƾ frame �� ���� �����մϴ�.
	// => sizeof(��������) + sizeof(��ȯŸ��::promise_type) + ��Ÿ ���� 
	//		 => ���������� ��� 200 ~ 400 byte ���� �����Ϸ����� �ٸ��ϴ�.

	// 2. promise_type �� ������ ȣ��

	// 3. promise_type �� get_return_object()�� ȣ���ؼ� Generator ����
	//		=> Generator �� coroutine �ڵ��� ����� ������ ����.

	// 4. promise_type �� initial_suspend() ȣ��

	// 5. initial_suspend() ��
	//    => suspend_always ��� �ڷ�ƾ �ߴ��ϰ� main ���� (3)���� ���� ��� ��ȯ
	//    => suspend_never  ��� �ڷ�ƾ �ߴ����� �ʰ� ��� ����
	//---------------------------------------
	std::cout << "foo 1 : " << std::endl;

	co_await myawait{};
	//----------------------------	
	//  myawait await_object;
	//	if (await_object.await_ready() == false)
	//	{
	//		await_object.await_suspend(�ڷ�ƾ �ڵ�);
	//
	//		���������� �ڷ�ƾ �ߴ��� main ���� ���ư�
	//	}
	// 
	//	=> �ٽ� �簳 �ɶ��� ������ ���� ����
	//	await_object.await_resume();
	//-------------------------------------

	std::cout << "foo 2 : " << std::endl;

	// promise��ü.final_suspend()
}

int main()
{
	Generator<int> g = foo();

	std::cout << "main 1" << std::endl;

	g();	// coroutine �ڵ�.resume() �ϹǷ� �ٽ�	
			// foo()�� �̵�.

	std::cout << "main 2" << std::endl;

	getchar();
}
