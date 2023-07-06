#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

template<typename T>
class counted_iterator
{
	T iterator;
	std::size_t count;
public:
	counted_iterator(T it, std::size_t sz)
		: iterator(it), count(sz) {}

	// 반복자의 기본 연산 : ++, *
	counted_iterator& operator++()
	{
		++iterator;
		--count;
		return *this;
	}
	// std::iter_value_t<T> : T가 반복자일때, 반복자가 가리키는 타입
	std::iter_value_t<T>& operator*()
	{
		return *iterator;
	}
};

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	counted_iterator ci(v.begin(), 5);

	while (ci != std::default_sentinel)
	{
		std::cout << *ci << std::endl;
		++ci;
	}
}


