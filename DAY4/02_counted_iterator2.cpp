#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>


// counted_iterator 같은 반복자가 끝에 도달했는지 체크 하려면
// 
// if ( ci == 끝을 나타내는 객체) 처럼 사용하기 위한 객체가 필요 합니다.

// empty class 로 보초병(sentinel) 타입을 설계 합니다.

struct defualt_sentinel_t {};	// 실제 표준도 아무 멤버가 없는 empty 입니다.

defualt_sentinel_t default_sentinel;





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

	// 끝에 도달했는지 조사할수 있게 하기 위해 == 와 != 제공
	// => 핵심 : 인자로 받은 t를 사용할것은 아닙니다. 
	// => count 로만 판단하면 됩니다.

	// 핵심 : counter_iterator 는 
	// std::default_sentinel_t 타입의 객체하고만, ==, != 연산이 가능합니다
	bool operator==(const default_sentinel_t& t)
	{
		return count <= 0;
	}
	bool operator!=(const default_sentinel_t& t)
	{
		return count > 0;
	}
};


int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	counted_iterator ci(v.begin(), 5);

	while (ci != default_sentinel)
	{
		std::cout << *ci << std::endl;
		++ci;
	}
}


