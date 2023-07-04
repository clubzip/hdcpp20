#include <iostream>
#include <algorithm>
#include <concepts>
#include <vector>



template<typename InputIter, typename T>
InputIter find(InputIter first, InputIter last, const T& value)
{
	std::cout << "값 버전" << std::endl;
	return first;
}

// 아래 처럼 했어야 하는데.. 
// 결국 위 템플릿과 모양이 동일합니다.
// => error.
// => 그래서, find 라는 동일 이름을 사용할수 없었고, find_if 로 했습니다.
template<typename InputIter, typename Pred>
InputIter find(InputIter first, InputIter last, Pred f)
{
	std::cout << "조건자(함수) 버전" << std::endl;
	return first;
}




int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	
	// find    : 주어진 구간에서 "값" 검색
	// find_if : 주어진 구간에서 조건 검색(마지막 인자로 호출가능한 객체(callable object) 전달)
//	auto p1 = std::find   (std::begin(v), std::end(v), 3);
//	auto p2 = std::find_if(std::begin(v), std::end(v), [](int a) { return a % 3 == 0; } );

	// 그런데, 위 2개 알고리즘을 같은 이름 (find) 로 했으면 어땟을까 ?
	auto p1 = std::find(std::begin(v), std::end(v), 3);
	auto p2 = std::find(std::begin(v), std::end(v), [](int a) { return a % 3 == 0; });

}