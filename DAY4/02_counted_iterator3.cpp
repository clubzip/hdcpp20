#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	// �ٽ� 1. counted_iterator ����
	std::counted_iterator ci(v.begin(), 5);


	// �ٽ� 2. ������ ���� �����ߴ��� �� �ϴ� ���.
	while (ci != std::default_sentinel)
	{
		std::cout << *ci << std::endl;
		++ci;
	}

	// �ٽ� 3. common_iterator_type

	auto ret1 = std::find(v.begin(), v.end(), 3); // ��ü ���� �˻�


	std::counted_iterator ci2(v.begin(), 5);

//	auto ret2 = std::find(ci2, std::default_sentinel, 3); // error
					// => find �� 1, 2��° ���ڴ� ���� Ÿ�� �̾�� �մϴ�.
					// => ci2                   : std::counted_iterator
					//    std::default_sentinel : std::default_sentinel_t

	// Ư�� �ݺ���Ÿ�԰� sentinel �� ������ Ÿ���� ����� �ڵ� �Դϴ�.
	// => C++20 �� common_iterator
//	using ITER = std::common_iterator<std::counted_iterator<std::vector<int>::iterator>,
//									  std::default_sentinel_t> ;

	using ITER = std::common_iterator<decltype(ci2), std::default_sentinel_t>;

	auto ret2 = std::find(ITER(ci2), ITER(std::default_sentinel), 3); // ok
}



