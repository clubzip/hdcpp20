#include <iostream>

// T 가 포인터 인지 조사하는 방법 

// 1. 구조체 템플릿을 만들고 false 반환 ( value = false 로 하라는 의미)
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