#include <iostream>
#include <algorithm>
#include <concepts>
#include <vector>



template<typename InputIter, typename T>
	requires (!std::predicate<T, std::iter_value_t< InputIter> >)
InputIter myfind(InputIter first, InputIter last, const T& value)
{
	std::cout << "값 버전" << std::endl;
	return first;
}

// std::predicate : C++20의 제공하는 표준 concept 
// std::predicate<F, int> : F 가 인자한개(int타입)로 호출가능 하고, 
//						    반환값이 bool로 변환 가능하면 true

// std::predicate<F, int, int> : F가 인자 2개(int, int)의 조건자 인가 ?

template<typename InputIter, typename Pred>
	requires std::predicate<Pred, std::iter_value_t< InputIter> >

InputIter myfind(InputIter first, InputIter last, Pred f)
{
	std::cout << "조건자(함수) 버전" << std::endl;
	return first;
}

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	auto p1 = myfind(std::begin(v), std::end(v), 3);
	auto p2 = myfind(std::begin(v), std::end(v), [](int a) { return a % 3 == 0; });

	/*
	std::sort(v.begin(), v.end());
	std::sort(v); // 왜!! STL 에는 컨테이너를 직접 보내는 버전이 없나요 ??
				// => 만들수 없었습니다

	// 아래 버전을 생각해 보세요
	std::sort(v, 비교함수버전);		// 인자가 2개인 템플릿
	std::sort(v.begin(), v.end());	// 인자가 2개인 템플릿
							// => 결국 모양이 모두 인자가 2개인 템플릿입니다.
							// => 그래서 만들수 없었습니다.
							// => 하지만 C++20 부터는 컨테이너 버전 있습니다.
							//		=> 내일!!!
	*/
}