#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>	// 이 안에 이미 less, greater 가 있습니다
						// C++98 시절부터!!!~~

inline bool foo(int a, int b) { return a < b; }

int main()
{
	std::vector v = { 1,3,5,7,9,2,4,6,8,10 };

	std::sort(v.begin(), v.end()); // 기본 버전 : 오름 차순

	// 비교 함수 교체
	// 1. 일반 함수 - foo 가 인라인 치환 될수 없습니다. 느립니다.
	std::sort(v.begin(), v.end(), foo);

	// 2. 함수 객체 - cmp의 operator() 는 인라인 치환 됩니다. - 빠릅니다.
	std::less<int> cmp;
	std::sort(v.begin(), v.end(), cmp);
}