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
// 3��° ���ڰ� true �� ��츦 ���� �κ� Ư��ȭ
// ��, PAIR �� 1��° ���ڰ� empty �� ��츦 ���� �κ� Ư��ȭ �Դϴ�.
template<typename T1, typename T2>
struct PAIR<T1, T2, true> : public T1
{
	T2 second;
};

int main()
{
	PAIR<Empty, int> p1; // 2�� Ÿ���� ���������� ũ�Ⱑ 4�Դϴ�.
	PAIR<int, int>   p2; 

	std::cout << sizeof(p1) << std::endl;
	std::cout << sizeof(p2) << std::endl;
}