#include <iostream>
#include <memory>
#include <type_traits>

struct Empty
{
};

template<typename T1, typename T2, bool b = std::is_empty_v<T1>>
struct PAIR
{
	T1 first;
	T2 second;
};
// 3번째 인자가 true 인 경우를 위한 부분 특수화
// 즉, PAIR 의 1번째 인자가 empty 인 경우를 위한 부분 특수화 입니다.
template<typename T1, typename T2>
struct PAIR<T1, T2, true> : public T1
{
	T2 second;
};

int main()
{
	PAIR<Empty, int> p1; // 2개 타입을 보관하지만 크기가 4입니다.
	PAIR<int, int>   p2; 

	std::cout << sizeof(p1) << std::endl;
	std::cout << sizeof(p2) << std::endl;
}