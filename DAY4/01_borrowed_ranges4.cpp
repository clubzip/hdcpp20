#include <iostream>
#include <vector>
#include <ranges>
#include <string>
#include <string_view>

// C++20 에서 "특정 range 가 borrow" 인지 조사하는 기술.

// check borrowed range

// 1. variable template 제공
template<typename T>
constexpr bool enable_borrowed_range = false;

// 2. take_view 같은 view 를 만들때, take_view 는 borrowed 라고 특수화 합니다.
// => 핵심 : borrowed 인지를 알아내는 것이 아니라...
//			타입 설계자가 알려 주는 것
template<typename T> class take_view
{
	T& container;
	std::size_t count;
public:
	take_view(T& c, std::size_t sz) : container(c), count(sz) {}

	auto begin() { return container.begin(); }
	auto end() { return container.begin() + count; }
};

template<typename T>
constexpr bool enable_borrowed_range<take_view<T>> = true;

// 3. 이제 concept 으로 만들어서 제공합니다.
template<typename T>
concept borrowed_range = std::ranges::range<T> && enable_borrowed_range<T>;

//-----------------------------------------------------------------

template<typename T> void check(T& c)
{
	std::cout << std::boolalpha;

	std::cout << borrowed_range<T> << std::endl;
}


int main()
{
	std::vector v{ 1, 2, 3, 4, 5 };
	
	take_view tv(v, 5);

	check(v);  // false
	check(tv); // true

}


