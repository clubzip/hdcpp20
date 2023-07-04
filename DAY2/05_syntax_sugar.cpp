#include <concepts>
#include <iostream>

// �⺻ ���ø� : ���� ������ �����Ƿ� ��� Ÿ�Կ� ���ؼ� ���..
template<typename T> 
void f1(T a) 
{
	std::cout << "f1" << std::endl;
}

// ���� ������ ǥ���ϴ� ���
// 1. <> �ڿ� ǥ��, �⺻ ���
template<typename T> requires std::integral<T>
void f2(T a)
{
	std::cout << "f2" << std::endl;
}

// 2. () �ڿ� ǥ�⵵ ����
template<typename T> 
void f3(T a) requires std::integral<T>
{
	std::cout << "f3" << std::endl;
}

// 3. typename ��ġ�� ǥ�� ����
template< std::integral T >
void f4(T a) 
{
	std::cout << "f4" << std::endl;
}

// 4. �Լ� ���� ��ġ�� "concept_�̸� auto ����" �� ǥ�� ����
// => �Ʒ� �ڵ�� template ǥ�Ⱑ ������, template �Դϴ�.
void f5(std::integral auto a)
{
	std::cout << "f5" << std::endl;
}

// 5. ���� ������ �����ϸ� auto �� ���� �˴ϴ�.
// => �ᱹ f6 �� �������� ���� template �Դϴ�.
// void f6(std::integral auto a)
void f6(auto a)
{
	std::cout << "f6" << std::endl;
}

// C++20 ���� : �Լ� ���ڷ� auto ����Ҽ� �����ϴ�.
// C++20 ���� : �Լ� ���ڷ� auto ��밡�� �մϴ�. - template �Դϴ�.

void foo(auto a) {}						// �� �ڵ��
template<typename T> void foo(T a) {}	// �� �ڵ�� ������ �����մϴ�.
 

void goo(auto a) {} // ���������� ���� template
void goo(std::integral auto a) {} // ���������� �ִ� template

// sytax sugar : ������ ������..
//			     ������ �����ѵ�, ���ϰ� ����Ҽ� �ֵ���
//				�ٸ� ǥ����� �����ϴ� ��

int main()
{
	f1(10);
	f2(10);
	f3(10); 
	f4(10);
	f5(10);
}