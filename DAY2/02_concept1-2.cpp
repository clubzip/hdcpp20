#include <iostream>
#include <type_traits>
#include <vector>

// A. begin, end 멤버 함수가 있지만 반환타입이 void 입니다.
class A
{
public:
	void begin() {}
	void end() {}
};
// B. begin, end 의 반환타입이 포인터 입니다.
class B
{
public:
	int* begin() { return 0; }
	int* end()   { return 0; }
};



template<typename T>
concept container = requires(T & c)
{
	// 아래 처럼 만들면
	// 1. std::begin() 의 인자로 보낼수 있거나
	// 2. c.begin() 이 있어도 됩니다.
//	std::begin(c);  // 이순간, c.begin() 을 다시 호출하는 원리
//	std::end(c);

	// 보다 엄격하게 하려면
	// "begin(), end() 의 반환값의 타입이 반복자 이어야 한다." 
	// 라는 조건이 필요 합니다.
//	{ std::begin(c) } -> std::input_iterator;
//	{ std::end(c) }   -> std::input_iterator;

	// 위 코드 대신에 아래 처럼 해도 됩니다.
	// std::begin(c) : c.begin()의 반환 타입을 조사하지않음
	// std::ranges::begin(c) : c.begin()의 반환 타입이 iterator 가 아니면
	//						   컴파일 에러!! - 내일 자세히 배우게 됩니다.
	//						   C++20 에서 새롭게 나오는 begin()
	std::ranges::begin(c); 
	std::ranges::end(c);
};

template<typename T> void check(T& c)
{
//	bool b = container<T>;
		
	// 이미 표준에 위의 container 와 유사한것이 있습니다.
	// C++20 부터는 "container" 라는 용어 보다 "range" 라는 용어를 사용합니다.
	// => 의미는 내일 자세히.. 

	// std::ranges  : namespace 이름
	// range<T>     : concept 이름.
	bool b = std::ranges::range<T>;

	std::cout << b << std::endl;
}

int main()
{
	std::cout << std::boolalpha;

	A aaa;
	B bbb;

	check(aaa);
	check(bbb);
}