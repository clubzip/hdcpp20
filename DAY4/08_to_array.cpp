#include <iostream>
#include <vector>
#include <array>

// C++20 std::to_array
int main()
{
//	int x[10]{ 1,2,3,4,5,6,7,8,9,10 };
//	std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	std::array<int, 10>  a{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 

	// C++17 부터는 템플릿 인자 생략가능하므로, 사용하기 쉬워 졌습니다.
	int x[10]{ 1,2,3,4,5,6,7,8,9,10 };
	std::vector v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::array  a{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };


	// 배열         : 모든 요소가 stack 에 놓입니다.
	// std::vector : 모든 요소가 heap  에 놓입니다. 
	// std::array  : 모든 요소가 stack 에 놓입니다. 
	//			     실제 배열과 메모리 구조는 완벽히 동일
	//				 a.size() 등의 함수가 제공되어서 실제 배열보다는 편리
	
	// C++20 부터 std::array 를 쉽게 만드는 std::to_array() 제공.
	auto a1 = std::to_array("foo");		// std::array<char, 4>
	auto a2 = std::to_array( {1,2,3});	// std::array<int, 3>
	auto a3 = std::to_array( x);		// raw array => std::array
}
