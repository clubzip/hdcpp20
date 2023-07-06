#include <iostream>
#include <vector>
#include <ranges>
#include <string>
#include <string_view>

// C++20 ���� "Ư�� range �� borrow" ���� �����ϴ� ���.

// check borrowed range

// 1. variable template ����
template<typename T>
constexpr bool enable_borrowed_range = false;

// 2. take_view ���� view �� ���鶧, take_view �� borrowed ��� Ư��ȭ �մϴ�.
// => �ٽ� : borrowed ������ �˾Ƴ��� ���� �ƴ϶�...
//			Ÿ�� �����ڰ� �˷� �ִ� ��
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

// 3. ���� concept ���� ���� �����մϴ�.
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


