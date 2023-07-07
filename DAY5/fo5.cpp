// fo5
#include <iostream>

// 함수객체의 장점을 알았다면!!
// 함수객체를 제대로 만들어 봅시다.

// 아래 코드가 C++ 98 시절에 만들었던 "std::plus" 입니다.
template<typename T>
struct plus
{
	inline const T& operator()(const T& a, const T& b) const
	{
		return a + b;
	}
};

int main()
{
	plus<int> p;

	int n = p(1, 2);

	// 위 코드의 단점
	// => 1번째 인자와 2번째 인자가 같은 타입이어야 합니다.
	double d = p(1, 3.4); // 
}