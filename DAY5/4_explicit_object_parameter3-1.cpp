#include <iostream>
#include <ranges>
#include <vector>

// ���� �ڵ带 C++23 ���� �����

class view_interface
{
public:
	// take_view tv;
	// tv.size() �ϸ� size(tv) �� �˴ϴ�.
	// �׷� �Ʒ� T �� take_view �� �ǹǷ� ������ �ƴմϴ�.
	// �ᱹ, ĳ���� �ڵ尡 ��� "CRTP" ȿ���� ���� �˴ϴ�

	// �̷� Ư¡ ������ �� ����� ������ 
	// "Deducing this ( ��ü this �� Ÿ���� �߷��Ѵٴ� �ǹ�)" �Դϴ�.
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