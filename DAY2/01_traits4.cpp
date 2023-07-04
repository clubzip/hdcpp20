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

	// QA. const int& ���� const �� & �� ��� �����Ϸ���
	// C++11
	std::remove_const_t< std::remove_reference_t<const int&> > n1;
	// => ����

	// �Ʒ� �ڵ�� �� �Ʒ��� �����͸� �����غ�����
	std::remove_reference_t< std::remove_const_t<const int&> > n2;

	// const int* const p;	// �� const : ����Ű�� ���� const
							// �� const : p�� const
	std::remove_pointer_t< std::remove_const_t<const int* const>> n3;
				// ���� const �� ����.. 

	// reference ��ü : const pointer �Դϴ�.

	int& r1 = n;		// int* const r1 = &n �Դϴ�.
	const int& r2 = n;  // const int* const r2 = &n �Դϴ�.

	// C++20 ������ remove_cvref �� �߰� �Ǿ����ϴ�.
	// remove_const : const ������
	// remove_cv    : const, volatile ����
	// remove_reference : reference ����
	// remove_cvref : const, volatile, reference ���� - C++20

}