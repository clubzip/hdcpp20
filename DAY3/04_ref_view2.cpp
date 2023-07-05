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

	// Ŭ���� ���ο� ���� ����� ������ "����Ʈ ���Կ����ڴ� �������� �ʽ��ϴ�."
	// ����ڰ� ���� �����ؾ� �մϴ�.
	// => �׷���, �Ʒ� ó�� �����ϸ� �ᱹ view �� �̵����� �ʰ�,
	//    view �� ����Ű�� vector ���� ���Ե˴ϴ�.
	take_view1& operator=(const take_view1& other)
	{
		if (this == &other) return *this;

		container = other.container;
		count = other.count;

		return *this;
	};
};

// raw reference ��� ref_view �� ����ϸ�
// ���ü�� �ƴ� view ������ ������ �˴ϴ�.
template<typename T> class take_view2
{
//	T& container;
	ref_view<T> container; // �̵� ������ ����(�ᱹ ������) ���

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