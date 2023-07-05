#include <iostream>
#include <ranges>

// std::ranges::begin �� ���� 1. 

// ����ڰ� ���� �����̳ʸ� ������µ�.. 

// 1. begin/end �� ��� �Լ��� ���� ���
struct MyContainer1
{
	int* begin() { return 0; }
	int* end() { return 0; }
};
// 2. begin/end �� �Ϲ� �Լ��� ���� ���
struct MyContainer2
{
};
int* begin(MyContainer2& mc) { return 0; }
int* end(MyContainer2& mc) { return 0; }

int main()
{
	MyContainer1 mc1;
	MyContainer2 mc2;

	// 1. ����ڰ� ���� begin �� ���� ȣ���Ҷ�
	auto a1 = mc1.begin(); // ok
	auto a2 = begin(mc2);  // ok

	// 2. std::begin() �� ����Ҷ�
	auto p1 = std::begin(mc1); // ok. ������ mc1.begin() �� �ٽ� ȣ��
//	auto p2 = std::begin(mc2); // error. 

	// 3. std::ranges::begin() �� ��� ����.
	auto p3 = std::ranges::begin(mc1);
	auto p4 = std::ranges::begin(mc2);
}
