#include <iostream>
#include <memory>

struct Empty
{
};

// C++ 표준의 pair 를 직접 구현해 봅시다.
// pair : 서로 다른 타입 2개를 보관하는 구조체.
/*
template<typename T1, typename T2> struct PAIR
{
	T1 first;
	T2 second;
};
*/
// 구조체의 1번째 멤버는 결국 상속 받는 것과 동일한 메모리 구조 입니다.
template<typename T1, typename T2> 
struct PAIR : public T1
{
	T2 second;
};


int main()
{
	PAIR<Empty, int> p1;
	PAIR<int,   int> p2; // 하지만 이 경우는 에러..

	std::cout << sizeof(p1) << std::endl; 
	std::cout << sizeof(p2) << std::endl; 
}