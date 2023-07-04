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

}