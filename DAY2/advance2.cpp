// advance1
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>

// 반복자의 5가지 카테고리(C++98 시절에 정의 한것)

// 입력 반복자 : n = *p, ++p  
// 출력 반복자 : *p = n, ++p

// 위 2개는 멀티 패스를 보장할수 없고,
// 아래 3개는 멀티 패스를 보장해야 합니다.

// 전진형 반복자 : n = *p, ++p         => 싱글리스트의 반복자
// 양방향 반복자 :	 n = *p, ++p, --p	 => 더블리스트의 반복자

// 임의접근 반복자 : n = *p, ++p, --p, +, -, []   => 연속된 메모리와 유사
//												vector의반복자

int main()
{
	std::list<int>         s1 = { 1,2,3 }; // 더블 리스트
	std::forward_list<int> s2 = { 1,2,3 }; // 싱글 리스트
	std::vector<int> v1 = { 1,2,3 };

	// 왜 ?? 5개 분류가 중요한가요 ?
	// => STL 알고리즘은 자신이 요구하는 반복자가 정해져 있습니다.

	// find : 1, 2번째 인자가 반복자 입니다.
	//        => 최소 요구 조건을 5개 분류에서 선택해 보세요.
	//		  => 입력 반복자
	auto ret = std::find(v1.begin(), v1.end(), 3);

	std::reverse( s1.begin(), s1.end() ); 
				// => 인자로 전달되는 반복자는 ++ 와 --가 되야 합니다.
				// => 양방향

	std::reverse(s2.begin(), s2.end());
				// error. 양방향 반복자를 요구하는데
				// s2는 싱글리스트 이므로 전진형 반복자 입니다.
				// 요구 조건을 만족하지 않으므로 error 입니다.
				// 에러 메세지는 결국 -- 가 안되는데, -- 하려고 하므로 에러
}
// cppreference.com 에서 algorithm 라이브러리.