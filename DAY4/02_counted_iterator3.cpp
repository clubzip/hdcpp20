#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	// 핵심 1. counted_iterator 개념
	std::counted_iterator ci(v.begin(), 5);


	// 핵심 2. 구간의 끝에 도달했는지 비교 하는 방법.
	while (ci != std::default_sentinel)
	{
		std::cout << *ci << std::endl;
		++ci;
	}

	// 핵심 3. common_iterator_type

	auto ret1 = std::find(v.begin(), v.end(), 3); // 전체 구간 검색


	std::counted_iterator ci2(v.begin(), 5);

//	auto ret2 = std::find(ci2, std::default_sentinel, 3); // error
					// => find 의 1, 2번째 인자는 같은 타입 이어야 합니다.
					// => ci2                   : std::counted_iterator
					//    std::default_sentinel : std::default_sentinel_t

	// 특정 반복자타입과 sentinel 의 공통의 타입을 만드는 코드 입니다.
	// => C++20 의 common_iterator
//	using ITER = std::common_iterator<std::counted_iterator<std::vector<int>::iterator>,
//									  std::default_sentinel_t> ;

	using ITER = std::common_iterator<decltype(ci2), std::default_sentinel_t>;

	auto ret2 = std::find(ITER(ci2), ITER(std::default_sentinel), 3); // ok
}



