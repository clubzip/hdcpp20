#include <iostream>
#include <vector>
#include <list>
#include <iterator>

template<typename T>
typename T::value_type sum(T first, T last)
{
	typename T::value_type s = 0;

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










