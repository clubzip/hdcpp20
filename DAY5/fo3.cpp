#include <iostream>

inline bool foo(int a, int b) { return a < b; }

struct less
{
	inline bool operator()(int a, int b) const { return a < b; }
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

	// foo �� cmp �� �ᱹ ������ ������ ���� �Լ� �Դϴ�.
	bool b1 = foo(1, 2);
	bool b2 = cmp(1, 2);


	// �Ʒ� �ڵ��� ���̸� ������ ���ô�.
	// => �ζ��� ġȯ���� �����ϼ���
	Sort(foo); // �Ϲ� �Լ� ����
	Sort(cmp); // �Լ� ��ü ����
}

// Sort(foo) ������ �����Ϸ��� ����� �ڵ� ( T=�Լ� �����ͷ� ����)
// foo(1,2) ó�� �ζ��� �Լ��� ���� ȣ���ϸ� �ζ��� ġȯ�˴ϴ�
// ������, �Ʒ� ó�� �Լ� �����Ϳ� ��Ƽ� ����ϸ� �ζ��� ġȯ�ɼ� �����ϴ�.
void Sort( bool(*cmp)(int, int) )
{
	bool b = cmp(1, 2); // (*cmp)(1,2)
}


// Sort(cmp) �� ����ϸ�(T=less �� ����)
void Sort( less cmp)
{
	bool b = cmp(1, 2); // cmp �� less ��� ���� �˰� �����Ƿ�
						// cmp.operator()(1, 2) �̹Ƿ�
						// => �Լ� �����Ͱ� �ƴ�, �Լ� �̸����� ���� ȣ���Ѱ�
						// => �ζ��� ġȯ�˴ϴ�.
}