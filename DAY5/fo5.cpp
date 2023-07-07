// fo5
#include <iostream>

// �Լ���ü�� ������ �˾Ҵٸ�!!
// �Լ���ü�� ����� ����� ���ô�.

// �Ʒ� �ڵ尡 C++ 98 ������ ������� "std::plus" �Դϴ�.
template<typename T>
struct plus
{
	inline const T& operator()(const T& a, const T& b) const
	{
		return a + b;
	}
};

int main()
{
	plus<int> p;

	int n = p(1, 2);

	// �� �ڵ��� ����
	// => 1��° ���ڿ� 2��° ���ڰ� ���� Ÿ���̾�� �մϴ�.
	double d = p(1, 3.4); // 
}