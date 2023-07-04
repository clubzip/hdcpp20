#include <iostream>

// �ٽ� 1. C++11 �� type_traits ����� ����ϱ����� ���
#include <type_traits>

// C++14 ���� �Ʒ� alias �� ǥ�ؿ� �߰��Ǿ����ϴ�.
template<typename T>
using remove_pointer_t = typename std::remove_pointer<T>::type;


// C++17 ���� �Ʒ� ������ ���Դϴ�. 
// "using alias" �� �ƴ� "variable template" �̶�� C++17 �������
template<typename T>
constexpr bool is_pointer_v = std::is_pointer<T>::value;

template<typename T>
void foo(T a)
{
	// �ٽ� 2. Ÿ���� Ư���� ����
	bool b1 = std::is_pointer<T>::value;  // C++11
	bool b2 = std::is_pointer_v<T>;       // C++17 ���� ���Ե� ���


	// �ٽ� 3. T���� ������ Ÿ�Ծ�� - ::type �� Ÿ�� �̹Ƿ� "typename �ʿ�"
	typename std::remove_pointer<T>::type n; // C++11
	std::remove_pointer_t<T> n1;			 // C++14 ���� ����
}


int main()
{
	int n = 0;
	foo(&n);
}