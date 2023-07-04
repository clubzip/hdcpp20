#include <iostream>

// �ٽ� 1. C++11 �� type_traits ����� ����ϱ����� ���
#include <type_traits>

template<typename T>
void foo(T a)
{
	// �ٽ� 2. Ÿ���� Ư���� ����
	bool b1 = std::is_pointer<T>::value;

	// �ٽ� 3. T���� ������ Ÿ�Ծ��
	typename std::remove_pointer<T>::type n;
}
int main()
{
	int n = 0;
	foo(&n);
}