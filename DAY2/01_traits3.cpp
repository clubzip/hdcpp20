#include <iostream>
#include <type_traits>

// if (����)  : ����ð� ���,  ������ �����̸� ������� ����. 
//			    ������ �����̾ "���ø� => C++�Լ�" ���� ���Ե�

// if (����) constexpr : ������ �ð� ���
// => ������ �����̸� "���ø� => C++�Լ�" ���� ���Ծȵ�!
// => C++17 ���� ������ ���
// => ���ø� ���鶧 �θ� ���!!

template<typename T> 
void printv(const T& value)
{
//	if ( std::is_pointer<T>::value )
	if constexpr (std::is_pointer<T>::value)
		std::cout << value << " : " << *value << std::endl;
	else
		std::cout << value << std::endl;
}


int main()
{
	int n = 10;
	printv(n);
	printv(&n);
}