#include <iostream>
#include <coroutine>
#define log() std::cout << "==============> " << __func__ << std::endl 


// �ٽ� : Coroutine �⺻ �ڵ�ϼ�!!
// => �ٽ��� �ᱹ "Generator" Ŭ������ �˸� �˴ϴ�.(promise ����)
// => �����ϽǶ� Generator �� �Ϻ��� ������ ������

// => �ᱹ foo() ���� coroutine �� ������� "Generator<int>" �� ��ȯ�ϸ� �˴ϴ�.

// => �׷�,!! �Ź� ������ ���� C++ ǥ�ؿ��� �� ������� "Generator" �� �����ϸ�
//    �ȵǳ��� ??

// C++20 : coroutine �� ���� ������ ��������ϴ�.
//         Generator Ŭ������ ǥ������ ����⿡�� �ð��� �������ϴ�. 

// cppcoro : C++ ǥ�� ���̺귯���� �ƴ�����, C++ �ڷ�ƾ�� ���� ���̺귯��

// C++23 : <generator> �� �߰��� �����Դϴ�.



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


Generator<int> foo()
{
	std::cout << "foo 1" << std::endl;
	co_yield 10;

	std::cout << "foo 2" << std::endl;
	co_yield 20;
}

int main()
{
	Generator<int> g = foo();
	std::cout << "main 1" << std::endl;

	int ret1 = g();

	std::cout << "main 2" << std::endl;

	int ret2 = g();

	std::cout << "main 3" << std::endl;

}
