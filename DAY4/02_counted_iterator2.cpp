#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>


// counted_iterator ���� �ݺ��ڰ� ���� �����ߴ��� üũ �Ϸ���
// 
// if ( ci == ���� ��Ÿ���� ��ü) ó�� ����ϱ� ���� ��ü�� �ʿ� �մϴ�.

// empty class �� ���ʺ�(sentinel) Ÿ���� ���� �մϴ�.

struct defualt_sentinel_t {};	// ���� ǥ�ص� �ƹ� ����� ���� empty �Դϴ�.

defualt_sentinel_t default_sentinel;





template<typename T>
class counted_iterator
{
	T iterator;
	std::size_t count;
public:
	counted_iterator(T it, std::size_t sz)
		: iterator(it), count(sz) {}

	// �ݺ����� �⺻ ���� : ++, *
	counted_iterator& operator++()
	{
		++iterator;
		--count;
		return *this;
	}
	// std::iter_value_t<T> : T�� �ݺ����϶�, �ݺ��ڰ� ����Ű�� Ÿ��
	std::iter_value_t<T>& operator*()
	{
		return *iterator;
	}

	// ���� �����ߴ��� �����Ҽ� �ְ� �ϱ� ���� == �� != ����
	// => �ٽ� : ���ڷ� ���� t�� ����Ұ��� �ƴմϴ�. 
	// => count �θ� �Ǵ��ϸ� �˴ϴ�.

	// �ٽ� : counter_iterator �� 
	// std::default_sentinel_t Ÿ���� ��ü�ϰ�, ==, != ������ �����մϴ�
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


