#include <iostream>
#include <ranges>

// std::ranges::begin �� ���� 2. 

struct SomeType
{
	// int* �� �ݺ��� �Դϴ�.
	// int* begin() { return 0; }
	
	// int �� �ݺ��� �ƴմϴ�. ++�� �̵��ϰ�, *�� ��� �����Ҽ� �־��
	// �ݺ��� �Դϴ�
	int begin() { return 0; }
};

int main()
{
	SomeType st;

	auto p1 = std::begin(st); // st.begin()�� ȣ���ϴµ�.
							  // ��ȯ Ÿ���� �ݺ������� �������.

	auto p2 = std::ranges::begin(st);
						// st.begin() �� ��ȯ Ÿ����
						// �ݺ��ڰ� �ƴϸ� error.
}
