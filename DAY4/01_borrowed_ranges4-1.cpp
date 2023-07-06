#include <iostream>
#include <vector>
#include <ranges>
#include <string>
#include <string_view>

template<typename T> void check(T& c)
{
	std::cout << std::boolalpha;

	// 아래 코드는 "variable template" 을 직접 사용하는 것.
	std::cout << std::ranges::enable_borrowed_range<T> << std::endl;

	// 아래 코드는 "concept" 을 사용하는 것 - 권장
	// T가 
	// => "ranges" 이고 "enable_borrowed_range 가 true" 인지 2가지 확인
	// 앞에서 만든 borrowed_range concept 이 이미 표준에 있습니다.
	std::cout << std::ranges::borrowed_range<T> << std::endl;

	
}

int main()
{
	std::vector v{ 1, 2, 3, 4, 5 };
	std::string s = "hello";
	int x[3] = { 1,2,3 };
	std::string_view sv = s;
	std::ranges::take_view tv(v, 3);

	check(v);	// false
	check(s);	// false
	check(x);	// false
	check(sv);	// true
	check(tv);	// true
}


