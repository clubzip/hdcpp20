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
	// 컴파일러가 추가한 코드
	//---------------------------------------
	// 1. 코루틴 frame 을 힙에 생성합니다.
	// => sizeof(지역변수) + sizeof(반환타입::promise_type) + 기타 정보 
	//		 => 지역변수가 없어도 200 ~ 400 byte 정도 컴파일러마다 다릅니다.

	// 2. promise_type 의 생성자 호출

	// 3. promise_type 의 get_return_object()를 호출해서 Generator 생성
	//		=> Generator 가 coroutine 핸들을 멤버로 가지고 있음.

	// 4. promise_type 의 initial_suspend() 호출

	// 5. initial_suspend() 가
	//    => suspend_always 라면 코루틴 중단하고 main 으로 (3)에서 만들 결과 반환
	//    => suspend_never  라면 코루틴 중단하지 않고 계속 실행
	//---------------------------------------
	std::cout << "foo 1 : " << std::endl;

	co_await myawait{};
	//----------------------------	
	//  myawait await_object;
	//	if (await_object.await_ready() == false)
	//	{
	//		await_object.await_suspend(코루틴 핸들);
	//
	//		이지점에서 코루틴 중단후 main 으로 돌아감
	//	}
	// 
	//	=> 다시 재개 될때는 이지점 부터 수행
	//	await_object.await_resume();
	//-------------------------------------

	std::cout << "foo 2 : " << std::endl;

	// promise객체.final_suspend()
}

int main()
{
	Generator<int> g = foo();

	std::cout << "main 1" << std::endl;

	g();	// coroutine 핸들.resume() 하므로 다시	
			// foo()로 이동.

	std::cout << "main 2" << std::endl;

	getchar();
}
