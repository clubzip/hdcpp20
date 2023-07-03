#include <iostream>
#include <memory>

struct Freer
{
	void operator()(void* p) noexcept
	{
		free(p);
	}
};

int main()
{
	
	std::unique_ptr<int> p1(new int);	// new 로 할당한 경우,
										// p1의 소멸자가 delete 로 제거.
										// 
	// unique_ptr 의 삭제자 변경은 템플릿 2번째 인자로 함수 객체를 전달합니다.
	std::unique_ptr<int, Freer> p2(static_cast<int*>(malloc(sizeof(int))));


	// 결국 람다 표현식은 함수 객체를 만드는 표기법 입니다
	// 그렇다면 아래 처럼 사용할수 있을까요 ?
//	std::unique_ptr<int, [](int* p) { free(p); } >  p3(static_cast<int*>(malloc(sizeof(int))));
			// => error. 
			// => 람다 표현식의 최종 결과는 "임시객체" 이지 타입이 아닙니다.
			// => 템플릿 인자는 객체가 아닌 타입을 전달해야 합니다.

	std::unique_ptr<int, decltype([](int* p) { free(p); }) > p3(static_cast<int*>(malloc(sizeof(int))));
				// C++20 부터 됩니다.
				// C++17 이전에는 아래 처럼 해야 합니다.

}






template<typename T, typename D = std::default_delete<T>> class unique_ptr
{
	T* obj = nullptr;
public:
	~unique_ptr()
	{
	}
};
