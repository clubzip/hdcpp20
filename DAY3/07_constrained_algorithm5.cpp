#include <iostream>
#include <vector>
#include <string>

// step 3. projection 의 디폴트 값

// 인자로 받은 것을 그대로 반환하는 함수
// int foo(int a) { return a; }

// 위처럼 함수가 아닌 아래 같은 함수객체로 해야 "타입의 디폴트값"등을 사용하기 편리합니다.
// identity : 인자로 받은 것을 그대로 반환 하는 함수 객체
//			  C++11 의 완벽한 전달 기술 사용
struct identity
{
	template<typename T>
	constexpr T&& operator()(T&& arg) const noexcept
	{
		return std::forward<T>(arg);
	}
};
// identity f;
// auto ret = f(3.4); // ret 는 3.4  즉, 인자가 다시 반환

template<typename T, typename Projection = identity >
const T& Max(const T& a, const T& b, Projection proj = {} )
{
	return std::invoke(proj, a) < std::invoke(proj, b) ? b : a;										// (b.*proj)()
}

int main()
{
	std::string s1 = "ABC";
	std::string s2 = "XX";
		
//	auto ret = Max(s1, s2, &std::string::size);
	auto ret = Max(s1, s2);

	std::cout << ret << std::endl; 
}