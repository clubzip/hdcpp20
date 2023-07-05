#include <iostream>
#include <ranges>
#include <vector>

// 30여개의 다양한 view는 size, empty 등의 공통의 함수가 필요합니다.
// 각각 만드는 것이 아닌 "CRTP" 기술로 만들어 봅시다.

template<typename Derived>
class view_interface
{
	Derived& Cast() { return static_cast<Derived&>(*this); }

public:	
	int size()   { return Cast().end() - Cast().begin(); }
	bool empty() { return Cast().end() == Cast().begin(); }
};

template<typename T> 
class take_view : public view_interface< take_view<T> >
{
	std::ranges::ref_view<T> container;
	std::size_t count;
public:
	take_view(T& c, std::size_t sz) : container(c), count(sz) {}

	auto begin() { return container.begin(); }
	auto end() { return container.begin() + count; }
};

template<typename T> 
class reverse_view : public view_interface< reverse_view<T> >
{
	std::ranges::ref_view<T> container;
public:
	reverse_view(T& c) : container(c) {}

	auto begin(){ return container.rbegin(); }
	auto end()	{ return container.rend(); }
};



int main()
{
	std::vector v = { 1,2,3,4,5,6,7,8,9,10 };

	take_view tv(v, 5);
	reverse_view rv(v);

	std::cout << tv.size() << std::endl; // 5	
	std::cout << rv.size() << std::endl; // 10

}