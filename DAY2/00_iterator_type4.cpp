#include <iostream>
#include <vector>
#include <list>
#include <iterator>

template<typename T> 
void iter_type(T first)
{
	// T �� �ݺ����϶� T�� ����Ű�� ����� Ÿ���� ���� ���
	
	// ��� 1. auto ��� - �ݵ�� �캯 �ʿ�!
	auto s1 = *first; 

	// ��� 2. C++98 ��Ÿ��
	typename T::value_type s2; // T �� ������ ��� ����
	typename std::iterator_traits<T>::value_type s3; // T �� ������		
										// �� ok

	// ��� 3. C++20 ��Ÿ��
	std::iter_value_t<T> s4;
}



int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
}










