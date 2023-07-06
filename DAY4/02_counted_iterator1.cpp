#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

// C++20 ���� "counted_iterator" ��� �ݺ��ڰ� �߰��Ǿ����ϴ�.
// 
// counted_iterator / std::default_sentinel / std::common_iterator_type

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	auto first = v.begin();
	auto last = v.end();

	while (first != last)
	{
		std::cout << *first << std::endl;
		++first;
	}

	// C++20 counted_iterator 
	// => ���� �ݺ��ڷ� ���� Ư�� ������ ��ŭ�� �̵� ������ �ݺ���
	std::counted_iterator ci(v.begin(), 5);

	// ������ ���� �ݺ��� ó�� ++, * �� ����ϸ� �˴ϴ�.
	// ++ci;

	// �����̳ʿ��� ������ �ݺ��� : ���� �����ߴ����� std::end() �� ��
	// std::counted_iterator : std::default_sentinel �� ��
	while ( ci != std::default_sentinel )
	{
		std::cout << *ci << std::endl;
		++ci;
	}
}


