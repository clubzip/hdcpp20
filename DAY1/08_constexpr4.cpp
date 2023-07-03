#include <vector>
#include <string>
#include <numeric>

int main()
{
	// C++20 부터는 vector 도 constexpr 지원 해야 한다고 되어 있습니다.
	// 그런데.. 아직 컴파일러가 지원 안하고 있습니다.
	
	// 일반 vector : 모든 요소가 힙에 놓이게 됩니다.
	// constexpr vector : 힙이 아닌 다른 방식으로 구현됩니다.
	//						컴파일러마다 다름.
	constexpr std::vector v = { 1,2,3,4,5,6,7,8,9,10 };

	constexpr int c = std::accumulate(std::begin(v), std::end(v), 0);

}
