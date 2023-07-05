#include <vector>
#include <iostream>
#include <ranges>

template<typename T> class ref_view
{
	T* src;
public:
	ref_view(T& cont) : src(&cont) {}

	auto begin() { return src->begin(); }
	auto end() { return src->end(); }
	auto size() { return src->size(); }
};

template<typename T> class take_view1
{
	T& container;
	std::size_t count;
public:
	take_view1(T& c, std::size_t sz) : container(c), count(sz) {}

	auto begin() { return container.begin(); }
	auto end() { return container.begin() + count; }

	// 클래스 내부에 참조 멤버가 있으면 "디폴트 대입연산자는 제공되지 않습니다."
	// 사용자가 직접 구현해야 합니다.
	// => 그런데, 아래 처럼 구현하면 결국 view 가 이동하지 않고,
	//    view 가 가리키는 vector 끼리 대입됩니다.
	take_view1& operator=(const take_view1& other)
	{
		if (this == &other) return *this;

		container = other.container;
		count = other.count;

		return *this;
	};
};

// raw reference 대신 ref_view 를 사용하면
// 대상체가 아닌 view 끼리의 대입이 됩니다.
template<typename T> class take_view2
{
//	T& container;
	ref_view<T> container; // 이동 가능한 참조(결국 포인터) 사용

	std::size_t count;
public:
	take_view2(T& c, std::size_t sz) : container(c), count(sz) {}

	auto begin() { return container.begin(); }
	auto end() { return container.begin() + count; }

};

int main()
{
	std::vector<int> v1 = { 11,12,13,14,15 };
	std::vector<int> v2 = { 21,22,23,24,25 };
	take_view1 tv1(v1, 3);
	take_view1 tv2(v2, 5);

	tv1 = tv2;

	for (auto e : v1)
	{
		std::cout << e << ", ";
	}

	
}