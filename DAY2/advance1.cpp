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

	auto p1 = s1.begin();
	auto p2 = s2.begin();

	// 다음중 에러를 찾으세요 
	++p1;
	--p1;
	++p2;
	--p2;	// error. 싱글리스트는 자료구조 특징상
			//		  뒤로 이동할수 없습니다.
}