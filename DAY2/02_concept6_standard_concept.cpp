#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <concepts>
#include <iterator>
#include <ranges>  

template<typename T>
void check(T arg)
{
	// �Ʒ� �ִ� input_iterator, bidirectional_iterator, random_iterator
	// �� ��� �̸� ���ǵǾ� �ִ� concept �Դϴ�.
	// ��ó�� ���ʰ��� concept �� �̸� ���ǵǾ� �ֽ��ϴ�.
	std::cout << std::input_iterator<T> << std::endl;
	std::cout << std::bidirectional_iterator<T> << std::endl;
	std::cout << std::random_access_iterator<T> << std::endl;
}

int main()
{
	std::cout << std::boolalpha;

	std::vector<int> v = { 1,2,3 };
			// vector �ݺ��� : ++, -- �� �ƴ϶� +, - �� �����մϴ�.
			//				 random access iterator ��� �մϴ�.
	
	std::list<int>   s = { 1,2,3 };
			// list �ݺ��� : +, - �� �ȵǰ�, ++, -- �� �����մϴ�.
			//				bidirectional iterator ��� �մϴ�.

	int x[3] = { 1,2,3 };

	check(std::begin(v));
	check(std::begin(s));
	check(std::begin(x));

}