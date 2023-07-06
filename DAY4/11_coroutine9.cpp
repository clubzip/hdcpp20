#include <iostream>
#include <coroutine>
#define log() std::cout << "==============> " << __func__ << std::endl 


// Step 8. Generator �� ���� �����ڿ� move ������ 


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

	// ����� ������ ����
	Generator(const Generator&) = delete;
	Generator& operator=(const Generator&) = delete;

	// move �� move ������ ���
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


Generator<int> foo()
{
	//--------------------------
	// �����Ϸ��� ������ �ڵ尡 ����ǰ�
	// ���⼭ main ���� ���ư�..
	//--------------------------
	std::cout << "foo 1" << std::endl;

	co_yield 10;

	std::cout << "foo 2" << std::endl;

	co_yield 20;
}

int main()
{
	Generator<int> g = foo();
	
	// Generator �� �ᱹ "�ڷ�ƾ �ڵ�"�� ������ 
	// operator() ���� ���ؼ� ���� �簳�� ����մϴ�.

//	Generator<int> g1 = g; // �ȵǴ� ���� �����ϴ�.

	Generator<int> g2 = std::move(g); // �Ǵ°��� �����ϴ�.

}
