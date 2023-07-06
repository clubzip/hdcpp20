#include <iostream>
#include <coroutine>
#define log() std::cout << "==============> " << __func__ << std::endl 


// 핵심 : Coroutine 기본 코드완성!!
// => 핵심은 결국 "Generator" 클래스만 알면 됩니다.(promise 포함)
// => 복습하실때 Generator 를 완벽히 이해해 보세요

// => 결국 foo() 같은 coroutine 을 만들려면 "Generator<int>" 를 반환하면 됩니다.

// => 그럼,!! 매번 만들지 말고 C++ 표준에서 잘 만들어진 "Generator" 를 제공하면
//    안되나요 ??

// C++20 : coroutine 에 대한 문법만 만들었습니다.
//         Generator 클래스를 표준으로 만들기에는 시간이 없었습니다. 

// cppcoro : C++ 표준 라이브러리는 아니지만, C++ 코루틴을 위한 라이브러리

// C++23 : <generator> 가 추가될 예정입니다.



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
	// Generator 멤버 들
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
