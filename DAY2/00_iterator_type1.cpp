#include <iostream>
#include <vector>
#include <list>
#include <iterator>

// ������ ���� ���ϴ� sum �� ����� ���ô�.

// T �� �ݺ��� �϶�
// 1. �ݺ��ڰ� ����Ű�� Ÿ���� "T::value_type" ���� ǥ�� - C++98

// 2. T::value_type => �����Ϸ��� value_type �� Ÿ���� �ƴ� ������ �ؼ�
//						(static member data ������ �ؼ�)
//    typename T::value_type => �̷��� �ؾ� Ÿ������ �ؼ��˴ϴ�.

// �� �ҽ��� �ٽ� : "typename T::value_type" ǥ��� �˾� �μ��� - C++98

template<typename T>
typename T::value_type sum(T first, T last)
{
	typename T::value_type s = 0;

//	auto s = *first;

	while (first != last)
	{
		s += *first;
		++first;
	}
	return s;
}


int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	int s = sum(v.begin(), v.end());

	std::cout << s << std::endl; // 55
}










