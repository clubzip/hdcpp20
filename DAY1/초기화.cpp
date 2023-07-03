#include <iostream>

// C++11
// 1. ��� �����ڰ� ���� <== �ٽ�
// 2. ��� ����� public �̸�
// ����ü ó�� �ʱ�ȭ �����մϴ�
// ( .x = 10  �� ǥ����� C++20 ����)

// C++11 STL�� array
template<typename T, int N>
struct array
{
	T buff[N];

//	array(const array& other) {}
//	array() {}

	int size() const { return N; }
};

int main()
{
	array<int, 5> a = { 1,2,3,4,5 };
			// => �̷� ǥ����� �ǰ� �Ϸ��� �ǵ�������
			//	  ��� �����ڵ� ������ ���ƾ� �մϴ�(���� ������, move �����ڵ�)
}