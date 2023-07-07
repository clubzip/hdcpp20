#include <iostream>

// C++14 에서 std::plus 가 아래 처럼 변경되었습니다.

//template<typename T >			// C++98 의 이 코드가
template<typename T = void >	// C++14 에서 이렇게 변경
struct plus
{
	inline const T& operator()(const T& a, const T& b) const
	{
		return a + b;
	}
};

// plus<void> 처럼 사용할때는 구현을 변경합니다.
// => 즉, 이전에 plus 사용자가 void 를 넣은 경우는 없을 테니, 
// => 새로운 구현은 plus<void> 버전으로 제공
template<>
struct plus<void>
{
	template<typename T1, typename T2>
	inline auto operator()(const T1& a, const T2& b) const
	{
		return a + b;
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