#include <iostream>
#include <coroutine>
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
/*
struct suspend_never 
{
	constexpr bool await_ready() const noexcept {return true;}
	constexpr void await_suspend(coroutine_handle<>) const noexcept {}
	constexpr void await_resume() const noexcept {}
};
struct suspend_always 
{
	constexpr bool await_ready() const noexcept { return false; }
	constexpr void await_suspend(coroutine_handle<>) const noexcept {}
	constexpr void await_resume() const noexcept {}
};
*/

struct myawait
{
	// 아래 함수의 반환 값이
	// false : 코루틴 중단하고 main 으로 돌아가기
	// true  : 코루틴 중단하지 않고 계속 실행
//	bool await_ready() const noexcept { log(); return false; }
	bool await_ready() const noexcept { log(); return true; }

	void await_suspend(std::coroutine_handle<>) const noexcept { log(); }
	void await_resume() const noexcept { log(); }
};

Generator<int> foo()
{
	std::cout << "foo 1" << std::endl;
	
	co_await myawait{};

//	co_await std::suspend_always{};
				// suspend_always 라는 구조체의 임시객체를 만드는 코드.
				// "Await Object" 라고 합니다.
				// 위 한줄은 아래의 코드처럼 변경됩니다.
	//--------------------------------------------
	/*
	if (await_object.await_ready() == false)
	{
		await_object.await_suspend(코루틴 핸들);
		
		이지점에서 코루틴 중단후 main 으로 돌아감
	}
	// 재개 될때 
	await_object.await_resume(); 
	*/
	//--------------------------------------------
				

	std::cout << "foo 2" << std::endl;
}


int main()
{
	Generator<int> g = foo();
	std::cout << "main 1" << std::endl;

	g();
	std::cout << "main 2" << std::endl;
	g();

	std::cout << "main 3" << std::endl;

}
