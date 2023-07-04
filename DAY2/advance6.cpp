#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>
#include <iostream>
#include <type_traits>

// C++ 버전별 advance 구현
// => empty class 로 추상화된 개념을 타입화 하고
// C++98 : 반복자 설계자가 자신이 어떤 종류인지 알려주고, tag dispatching
// C++17 : 반복자 설계자가 자신이 어떤 종류인지 알려주고, if constexpr

// C++17 까지의 단점 : 반복자 설계자가 "약속된 iterator_category" 로
//				자신의 종류를 알려 주어야 합니다.
// => 만일 raw pointer(int*) 라면 iterator_category 라는 내포된 타입을
//    가질수 없습니다. (iterator_traits 등의 기술로 해결해야 합니다.)

// C++20 
// => 입력반복자, 양방향 반복자, 임의접근 반복자등의 추상화된 개념을
// => concept 으로 정의 합니다
// => if 문으로 조사해도 되고, require clauses(다음시간)으로 활용해도 됩니다.

// 반복자 설계자가 알려줄 필요 없습니다.

template<typename T>
void xadvance(T& p, int n)
{
	// 이제 타입이 "특정 개념"을 만족하면 보다 최적화된 구현을 제공합니다.
	// => 개념을 만족하는 가에 대한 조사는 "컴파일 시간"에 이루어 집니다.
	if constexpr ( std::random_access_iterator<T> )
		p = p + n;
	else
		while (n--)
			++p;
}






int main()
{
	std::list<int>   c = { 1,2,3,4, 5, 6, 7 };
	//	std::vector<int> c = { 1,2,3,4, 5, 6, 7 };

	auto p = c.begin();

	xadvance(p, 5);

	std::cout << *p << std::endl; // 6
}
