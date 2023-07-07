#include <iostream>

bool foo(int a, int b) { return a < b; }

struct less
{
	bool operator()(int a, int b) const { return a < b; }
};

// Sort �� ���������� ���ڷ� ���� �Լ��� ����� ȣ���Ѵٰ� ������ ������
template<typename T>
void Sort(T cmp)
{
	bool b = cmp(1, 2); // ����� ȣ��
}
int main()
{
	less cmp;

	// �Ʒ� �ڵ��� ���̸� ������ ���ô�.
	Sort(foo); // �Ϲ� �Լ� ����
	Sort(cmp); // �Լ� ��ü ����
}