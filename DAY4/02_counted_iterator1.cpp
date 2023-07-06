#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

// C++20 에서 "counted_iterator" 라는 반복자가 추가되었습니다.
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
	// => 기존 반복자로 부터 특정 갯수만 만큼만 이동 가능한 반복자
	std::counted_iterator ci(v.begin(), 5);

	// 사용법은 기존 반복자 처럼 ++, * 로 사용하면 됩니다.
	// ++ci;

	// 컨테이너에서 꺼내는 반복자 : 끝에 도달했는지를 std::end() 와 비교
	// std::counted_iterator : std::default_sentinel 과 비교
	while ( ci != std::default_sentinel )
	{
		std::cout << *ci << std::endl;
		++ci;
	}
}


