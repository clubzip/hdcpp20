#include <iostream>
#include <ranges>
#include <vector>

// deducing this ���� 2. ĳ���� ���� CRTP

// 1. �Ļ� Ŭ������ �̸��� ���ø� ���ڷ� �޾Ƽ�
// 2. �Ļ� Ŭ������ ���� ������ �Լ��� ��� Ŭ������ ȣ���Ҽ� �ִ� �ڵ�
// ���� C++20 ǥ���� "view_interface" �� �Ʒ� ó�� ����.

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