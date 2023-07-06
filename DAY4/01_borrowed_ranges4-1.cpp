#include <iostream>
#include <vector>
#include <ranges>
#include <string>
#include <string_view>

template<typename T> void check(T& c)
{
	std::cout << std::boolalpha;

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

	check(v);
	check(s);
	check(x);
	check(sv);
	check(tv);

	

}


