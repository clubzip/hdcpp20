#include <iostream>
#include <ranges>
#include <vector>

// 앞의 코드를 C++23 으로 만들면

class view_interface
{
public:
	// take_view tv;
	// tv.size() 하면 size(tv) 가 됩니다.
	// 그럼 아래 T 는 take_view 가 되므로 에러가 아닙니다.
	// 결국, 캐스팅 코드가 없어도 "CRTP" 효과를 보게 됩니다

	// 이런 특징 때문에 이 기술의 별명이 
	// "Deducing this ( 객체 this 의 타입을 추론한다는 의미)" 입니다.
	template<typename T>
	int size(this T& self)
	{
		return self.end() - self.begin();
	}
};

template<typename T>
class take_view : public view_interface
{
	std::ranges::ref_view<T> container;
	std::size_t count;
public:
	take_view(T& c, std::size_t sz) : container(c), count(sz) {}

	auto begin() { return container.begin(); }
	auto end() { return container.begin() + count; }
};

int main()
{
	std::vector v = { 1,2,3,4,5,6,7,8,9,10 };

	take_view tv(v, 5);

	std::cout << tv.size() << std::endl; 
			// => tv.size()
			// => size(tv)
}