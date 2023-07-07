#include <iostream>

bool foo(int a, int b) { return a < b; }

struct less
{
	bool operator()(int a, int b) const { return a < b; }
};

// Sort 는 내부적으로 인자로 받은 함수를 수백번 호출한다고 생각해 보세요
template<typename T>
void Sort(T cmp)
{
	bool b = cmp(1, 2); // 수백번 호출
}
int main()
{
	less cmp;

	// 아래 코드의 차이를 생각해 봅시다.
	Sort(foo); // 일반 함수 전달
	Sort(cmp); // 함수 객체 전달
}