#include <iostream>
#include <type_traits>	// C++11 ���� �߰��� ���
						// �� ��� �ȿ� �Ʒ� ���� is_pointer �� �ֽ��ϴ�
// T �� ������ ���� �����ϴ� ��� 

// 1. ����ü ���ø��� ����� false ��ȯ ( value = false �� �϶�� �ǹ�)
template<typename T> struct is_pointer
{
//	enum { value = false }; // ���� ��Ÿ��
	static constexpr bool value = false; // C++11 ���� ��Ÿ��
};
// 2. ������ �����ϵ��� �κ� Ư��ȭ ������ �����,  true ��ȯ(value = true)
template<typename T> struct is_pointer<T*>
{
//	enum { value = true };
	static constexpr bool value = true; 
};

template<typename T> 
void foo(const T& value)
{
	// T : int, int*
	//if   ( is_pointer<T>::value  )
	if (std::is_pointer<T>::value)
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