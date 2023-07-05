#include <iostream>

namespace mystd
{
	class string {};

	template<typename T> void max(const T& a, const T& b) 
	{
		std::cout << "std::max" << std::endl;
	}

	// C++20
	namespace ranges
	{
		/*
		template<typename T> void max(const T& a, const T& b)
		{
			std::cout << "std::ranges::max" << std::endl;
		}
		*/
		struct MaxFn
		{
			template<typename T> 
			void operator()(const T& a, const T& b)
			{
				std::cout << "std::ranges::max" << std::endl;
			}
		};
		MaxFn max; // max 는 함수가 아닌 함수 객체
	}
}

int main()
{
	mystd::string s1;
	mystd::string s2;

	mystd::max(s1, s2);			// C++98
	mystd::ranges::max(s1, s2);	// C++20 
	
	// 아래 코드를 생각해 봅시다.
	using namespace mystd::ranges; // C++20을 사용하겠다는 생각으로 open
	max(s1, s2);	// max 가 함수 라면 에러.!
					// max 가 함수 객체라면 에러 아님.


}