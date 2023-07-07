#include <iostream>
#include <ranges>
#include <vector>

// deducing this 장점 2. 캐스팅 없는 CRTP

// 1. 파생 클래스의 이름을 템플릿 인자로 받아서
// 2. 파생 클래스가 가진 고유의 함수를 기반 클래스에 호출할수 있는 코드
// 실제 C++20 표준의 "view_interface" 가 아래 처럼 구현.

template<typename Derived>
class view_interface
{
public:
	
	int size()
	{
		return static_cast<Derived&>(*this).end() - 
			   static_cast<Derived&>(*this).begin();
	}
};


template<typename T>
class take_view : public view_interface< take_view<T>   >
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

	std::cout << tv.size() << std::endl; // 5	
}