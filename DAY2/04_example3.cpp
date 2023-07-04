#include <iostream>
#include <algorithm>
#include <concepts>
#include <vector>
#include <list>

template<typename T> requires std::random_access_iterator<T>
void mysort(T first, T last)
{
	std::cout << "quick sort" << std::endl;
}

template<typename T> requires std::bidirectional_iterator<T>
void mysort(T first, T last)
{
	std::cout << "bubble sort" << std::endl;
}

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	std::list<int>   s = { 1,2,3,4,5,6,7,8,9,10 };

	// STL �� std::sort �� ����Ʈ �Դϴ�. - ���� ���� �ݺ��ڸ� ���� ����
	std::sort(v.begin(), v.end()); // ok
//	std::sort(s.begin(), s.end()); // error

	s.sort();	// ok. list �� sort �Ҷ��� ��� �Լ� ����ϸ� �˴ϴ�.
				// �� ��Ʈ�� �ƴ� �ٸ� �˰���(bubble, selection ��)

	mysort(s.begin(), s.end());
	mysort(v.begin(), v.end());

	// �ٽ� : vector �� �ݺ��ڴ�
	//       std::random_access_iterator �� std::bidirectional_iterator
	//	     �� ��� �����մϴ�.
	//	     => ������ ������ �ƴմϴ�.
	//		 => random_access_iterator concept = bidirectional_iterator + �߰�����
	//		 => �̹Ƿ� random_access_iterator ���� ���.
}