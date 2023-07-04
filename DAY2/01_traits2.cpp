#include <iostream>

// T �� ������ ���� �����ϴ� ��� 

// 1. ����ü ���ø��� ����� false ��ȯ ( value = false �� �϶�� �ǹ�)
template<typename T> struct is_pointer
{
	enum { value = false };
};

template<typename T> 
void foo(const T& value)
{
	if ( is_pointer<T>::value  )
		std::cout << "pointer" << std::endl;
	else 
		std::cout << "not pointer" << std::endl;
}

int main()
{
	int n = 10;
	foo(n);
	foo(&n);
}