#include <iostream>
#include <coroutine>

#define log() std::cout << __func__ << std::endl 

// C++ 코루틴은 어떻게 동작하는가 ?
// 원리를 살펴보는 코드..
// 주석을 잘 생각해보세요..

// 핵심 : coroutine framework 를 힙에 생성할때
// 1. promise_type 안에 operator new() 가 있으면 사용하고
// 2. 없으면 global new 사용합니다.


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
		std::suspend_always final_suspend() noexcept { return {}; }
		Generator get_return_object() { return {}; };
		void unhandled_exception() {}
		void return_void() {}

		void* operator new(std::size_t sz)
		{
			void* p = ::operator new(sz);
			printf("new : %p, %d bytes\n", p, sz);
			return p;
		}
		void operator delete(void* p) noexcept
		{
			printf("delete : %p\n", p);
			::operator delete(p);
		}
	};
	using promise_type = promise;
};
Generator foo()
{
	int x[100];  // 400 byte.. coroutine framework 크기가
	x[0] = 0;	 // 400바이트 증가
	// 함수 안에 "co_await" 등의 키워드가 있으면 컴파일러가 아래 코드를 생성합니다.
	//---------------------------------------------
	// 1. 코루틴 frame 을 힙에 생성합니다.
	// => sizeof(지역변수) + sizeof(반환타입::promise_type) + 기타 정보 
	//		 => 지역변수가 없어도 200 ~ 400 byte 정도 컴파일러마다 다릅니다.

	// 2. promise_type 의 생성자 호출

	// 3. promise_type 의 get_return_object()를 호출해서 Generator 생성

	// 4. promise_type 의 initial_suspend() 호출

	// 5. (3) 에서 생성된 객체를 반환.. 
	//    => 즉, 여기서 main 으로 반환




	//---------------------------------------------
	std::cout << "foo 1" << std::endl;

	co_await std::suspend_always{};

	std::cout << "foo 2" << std::endl;
}



int main()
{
	foo();
}
