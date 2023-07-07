#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main()
{
	std::vector v = { 1,3,5,7,9,2,4,6,8,10 };

	// sort() 비교 정책 변경하는 법.
	std::less<int> cmp;
	std::sort(v.begin(), v.end(), cmp); // 함수 객체를 만들어서 전달

	std::sort(v.begin(), v.end(), std::less<int>() ); // 임시객체로 전달

	std::sort(v.begin(), v.end(), std::less<void>()); // void 버전 사용
	std::sort(v.begin(), v.end(), std::less<>());     // void 버전 사용.

	std::sort(v.begin(), v.end(), std::less()); // void 버전 사용. C++17 부터
	
	std::sort(v.begin(), v.end(), std::less{}); //() 대신 {}도 가능
						// => 요즘은 이렇게 널리 사용

	// 3번째 인자로 람다 표현식 사용해도 되지만(결국 함수 객체이므로 동일 효과)
	// 이미 less 가 있으므로 std::less 사용이 더 편리합니다.
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; } );
}