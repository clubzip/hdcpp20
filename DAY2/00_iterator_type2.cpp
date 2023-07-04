#include <iostream>
#include <vector>
#include <list>
#include <iterator>

// std::begin(v) ����
// 1. v �� STL container �̸� : T �� ��ü�� �ݺ���( class �� �����)
// 2. v �� raw array �̸�     : T �� raw pointer( int* )

// �ݺ����� 2���� ����
// 1. class �� ������� �ݺ��� ( vector �� list �ݺ��� )
// 2. raw pointer => C++���� raw pointer �� �ݺ����� �����Դϴ�.

// �ݺ����� ������ �� 2������ �ֱ⶧���� �Ʒ� sum ���� �Լ� ����Ⱑ
// ��ƽ��ϴ�.
// �� ������ �ذ��ϴ� ������ "iterator_traits" �Դϴ�.

template<typename T> struct iterator_traits
{
	using value_type = typename T::value_type;
};

// T �� "raw pointer" �� ��쿡�� ������ �ٸ��� �ϱ� ����
// �κ� Ư��ȭ ���� ���
template<typename T> struct iterator_traits<T*>
{
	using value_type = T;
};

template<typename T>
typename iterator_traits<T>::value_type sum(T first, T last)
{
//	typename T::value_type s = 0;

	typename iterator_traits<T>::value_type s = 0;


	while (first != last)
	{
		s += *first;
		++first;
	}
	return s;
}


int main()
{
//	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
//	std::list<int>   v = { 1,2,3,4,5,6,7,8,9,10 };

	// raw array �� �ᱹ�� �����̳�(�������� ���� ����) �Դϴ�.
	int v[10] = { 1,2,3,4,5,6,7,8,9,10 };

//	int s = sum(v.begin(), v.end()); // ��� �Լ� begin() ���
									 // => raw array �� ��� ����

	int s = sum(std::begin(v), std::end(v)); // �Ϲ� �Լ� begin
											 // => raw array ������
											 // => C++11 ���� ����

	std::cout << s << std::endl; // 55
}










