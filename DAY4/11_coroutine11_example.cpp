#include <iostream>
#include <coroutine>
#define log() std::cout << "==============> " << __func__ << std::endl 

// ����!!

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



public:
	// Generator �� �ݺ���
	// => �ᱹ �ڷ�ƾ �ڵ��� �����ϴٰ� ++ �� �����Ҽ� �ְ� �ϸ� �˴ϴ�.
	class Iterator
	{
		std::coroutine_handle<promise_type> coro_handle;;
	public:
		Iterator(std::coroutine_handle<promise_type> h)
			:coro_handle(h) {}

		void operator++() { coro_handle.resume(); }

		const T& operator*() { return coro_handle.promise().get_value(); }

		bool operator==(const std::default_sentinel_t& s) const
		{
			return !coro_handle || coro_handle.done();
		}
	};

	Iterator begin()
	{
		if (coro_handle)
		{
			coro_handle.resume();
		}
		return Iterator(coro_handle);
	}

	std::default_sentinel_t end() { return {}; }
};
//-----------------------------------
Generator<int> range(int first, int last)
{
	while (first < last)
	{
		co_yield first++;
	}
}

int main()
{
	// ���̽��� range �� ����� ���ô�.
	// range ���� 1. () �� ȣ��
	auto g = range(15, 30);

	std::cout << g() << std::endl; // 15
	std::cout << g() << std::endl; // 16
	std::cout << g() << std::endl; // 17

	
	// ��� 2. range-for �� �ֱ�
	// => range-for ������ �����ϼ���
	
	for (int e : range(15, 30) )	// 15 ~ 29 ������ ���������� ��ȯ!
	{
		std::cout << e << ", ";
	}
	
//	auto obj = range(15, 30);
//	auto first = obj.begin();
//	auto last = obj.end();


}
