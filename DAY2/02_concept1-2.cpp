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
	{ std::begin(c) } -> std::input_iterator;
	{ std::end(c) }   -> std::input_iterator;
};



template<typename T> void check(T& c)
{
	bool b = container<T>;
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