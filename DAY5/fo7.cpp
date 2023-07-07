#include <iostream>

// 실제 C++ 표준 구현은 아래 코드 입니다.

template<typename T = void >	
struct plus
{
	[[nodiscard]] constexpr 
	const T& operator()(const T& a, const T& b) const noexcept
	{
		return a + b;
	}
};

// plus<void> 버전은 "C++11 의 완벽한 전달" 로 구현 됩니다.
template<>
struct plus<void>
{
	template<typename T1, typename T2>
	[[nodiscard]] constexpr 
	auto operator()(T1&& a, T2&& b) const noexcept
	{
		return std::forward<T1>(a) + std::forward<T2>(b);
	}
};

int main()
{
	plus<int> p1;	// int + int 만 가능
	plus<void> p2;	// T1 + T2

	plus<> p3;		// T=void 이므로 plus<void> 와 동일

	plus p3;		// C++17 부터 타입에 디폴트 값이 있으면
	// <> 자체를 생략가능합니다.

	auto ret1 = p2(1, 3.4);

}