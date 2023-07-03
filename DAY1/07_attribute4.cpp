#include <iostream>
#include <memory>

struct Empty
{
};

// C++ ǥ���� pair �� ���� ������ ���ô�.
// pair : ���� �ٸ� Ÿ�� 2���� �����ϴ� ����ü.
/*
template<typename T1, typename T2> struct PAIR
{
	T1 first;
	T2 second;
};
*/
// ����ü�� 1��° ����� �ᱹ ��� �޴� �Ͱ� ������ �޸� ���� �Դϴ�.
template<typename T1, typename T2> 
struct PAIR : public T1
{
	T2 second;
};


int main()
{
	PAIR<Empty, int> p1;
	PAIR<int,   int> p2; // ������ �� ���� ����..

	std::cout << sizeof(p1) << std::endl; 
	std::cout << sizeof(p2) << std::endl; 
}