#include <iostream>
#include <ranges>

// std::ranges::size() �̾߱�

struct MyContainer1
{
	int* begin() { return 0; }
	int* end() { return 0; }
};

int main()
{
	MyContainer1 mc1;

	auto sz0 = mc1.size();		// error. mc1 ���� size()�Լ� �����ϴ�.

	auto sz1 = std::size(mc1);	// error. �ᱹ ���ڵ�� mc1.size() ���
				
	auto sz2 = std::ranges::size(mc1); // ok
		// 1. mc1.size() �� ������ ���
		// 2. mc1.size() �� ������ "mc1.end() - mc1.begin()" �� �����ϸ� ���
		// 3. �ݺ��ڰ� random �� �ƴϸ� std::distance(mc1.begin(), mc1.end())

}