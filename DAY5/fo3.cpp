#include <iostream>

inline bool foo(int a, int b) { return a < b; }

struct less
{
	inline bool operator()(int a, int b) const { return a < b; }
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

	// foo 와 cmp 는 결국 사용법이 동일한 이항 함수 입니다.
	bool b1 = foo(1, 2);
	bool b2 = cmp(1, 2);


	// 아래 코드의 차이를 생각해 봅시다.
	// => 인라인 치환성을 생각하세요
	Sort(foo); // 일반 함수 전달
	Sort(cmp); // 함수 객체 전달
}

// Sort(foo) 했을때 컴파일러가 만드는 코드 ( T=함수 포인터로 결정)
// foo(1,2) 처럼 인라인 함수를 직접 호출하면 인라인 치환됩니다
// 하지만, 아래 처럼 함수 포인터에 담아서 사용하면 인라인 치환될수 없습니다.
void Sort( bool(*cmp)(int, int) )
{
	bool b = cmp(1, 2); // (*cmp)(1,2)
}


// Sort(cmp) 로 사용하면(T=less 로 결정)
void Sort( less cmp)
{
	bool b = cmp(1, 2); // cmp 가 less 라는 것을 알고 있으므로
						// cmp.operator()(1, 2) 이므로
						// => 함수 포인터가 아닌, 함수 이름으로 직접 호출한것
						// => 인라인 치환됩니다.
}