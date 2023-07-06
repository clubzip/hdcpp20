#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector v = { 1,2,3,1,2,3,1,2,3,1 };

	// C++98 : erase-remove idioms 
	// STL 알고리즘은 "자신이 어떤 컨테이너에 연산하는지" 알수 없습니다.
	// => 그래서, 아래 remove 는 3을 만나면 뒤의 요소를 앞으로 옮기게 됩니다.
//	auto p = std::remove(v.begin(), v.end(), 3);

	// 컨테이너 자체를 줄이려면 "일반화된 알고리즘(멤버가 아닌 함수)" 이 아니라
	// 컨테이너 자체의 멤버 함수를 사용해야 합니다.
//	v.erase(p, v.end());

	// 위 기술을 흔히 아래 처럼 한줄로 하곤 했습니다.
	// => 아래 코드를 흔히 "erase-remove" 라고 불렀습니다.
//	v.erase( std::remove(v.begin(), v.end(), 3), v.end());
	
	// C++20 에서는 실제 컨테이너를 줄일수 있는 std::erase() 가 나왔습니다.
	// 원리 : erase(vector)
	//		 erase(list)
	//       erase(deque) 등으로 모든 컨테이너에 대해 오버로딩한것
	std::erase(v , 3);

	for (auto n : v) 
		std::cout << n << ", ";

	std::cout << std::endl;
}
