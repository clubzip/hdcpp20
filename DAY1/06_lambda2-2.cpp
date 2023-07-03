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
	// 삭제자로 함수 객체 전달 - ok!!
	std::unique_ptr<int, Freer> p1((int*)malloc(sizeof(int)));


//	std::unique_ptr<int, [](int* p) { free(p); } > p2((int*)malloc(sizeof(int)));
					// error 
					// 람다표현식의 결과는 객체이지, 타입이 아닙니다.

//	std::unique_ptr<int, decltype( [](int* p) { free(p); } )  > p2((int*)malloc(sizeof(int)));
					// C++20 이전에는 에러
					// => 람다 표현식은 평가 되지 않은 표현식에 
					//	  넣을수 없다.

	auto del = [](int* p) { free(p); };

//	std::unique_ptr<int, decltype(del) > p2((int*)malloc(sizeof(int)));
			// => 템플릿 인자로 전달은 가능.
			// => 하지만 람다표현식이 만든 타입은 디폴트 생성자가 없어서
			//	  error ( C++20 이전)

	// 결국 C++20 이전에는 아래 처럼 해야 합니다. 
	// => effective modern C++ 에 있는 내용.
	// 
	// 1. 람다 표현식을 먼저 auto 변수에 담으세요
	auto del2 = [](int* p) { free(p); }; 

	// 2. 타입을 전달하고, 생성자로 del2 도 전달하세요
	std::unique_ptr<int, decltype(del2)> 
					p2((int*)malloc(sizeof(int)), del2);

	// 하지만 C++20 부터는
	// => 람다표현식이 평가되지 않는 표현식에 넣을수 있고
	// => 디폴트 생성자도 있으므로
	// 아래 처럼 하면 됩니다.
	std::unique_ptr<int, decltype([](int* p) { free(p); })>
									p2((int*)malloc(sizeof(int)));
}




template<typename T, typename D = std::default_delete<T>>
class unique_ptr
{
	D del;
	T* obj = nullptr;
public:
	unique_ptr(T* p, const D& d) : obj(p), del(d) {}

	~unique_ptr()
	{
		del(obj);
	}
};
