// 07_constrained_algorithm0
#include <vector>
#include <algorithm>

int main()
{
	std::vector v = { 1,2,3,4,5 };

	// C++98 �� STL �˰��� : �Լ� ���ڷ� �ݺ��ڸ� �����մϴ�.
	auto ret1 = std::find(v.begin(), v.end(), 3);


	// C++20 �� ���ο� �˰��� : �ݺ��ڵ� �����ϰ�, �����̳ʵ� �����մϴ�.
	auto ret2 = std::ranges::find(v.begin(), v.end(), 3); // ok
	auto ret3 = std::ranges::find(v, 3);				  // ok
}