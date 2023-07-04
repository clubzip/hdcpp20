#include <iostream>
#include <algorithm>
#include <type_traits>
#include <concepts>
#include <vector>

// ordering
template<typename T> 
concept Concept1 = sizeof(T) >= 4; 


template<typename T> 
concept Concept2 = std::is_integral_v<T>; 


template<typename T> 
concept Concept3 = Concept1<T> && Concept2<T>; 


template<typename T> requires Concept1<T>
void foo(T a)
{
	std::cout << "1" << std::endl;
}

// Ÿ���� ������ �����ϴ� ���ø��� 2�� �̻� ������
// => ���� ���� ������ �����ϴ� ���ø��� �ִٸ� ������ �ƴϰ� �ش� ������ ����մϴ�.
// 
// 1�� foo : Concept1<T>
// 2�� foo : Concept1<T> && Concept2<T>
// 
//template<typename T> requires Concept2<T>
template<typename T> requires Concept3<T>
void foo(T a)
{
	std::cout << "2" << std::endl;
}

int main()
{
	foo(3);
//	foo(3.4); 
}