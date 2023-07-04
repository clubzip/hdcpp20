#include <iostream>
#include <algorithm>
#include <concepts>
#include <vector>



template<typename InputIter, typename T>
	requires (!std::predicate<T, std::iter_value_t< InputIter> >)
InputIter myfind(InputIter first, InputIter last, const T& value)
{
	std::cout << "�� ����" << std::endl;
	return first;
}

// std::predicate : C++20�� �����ϴ� ǥ�� concept 
// std::predicate<F, int> : F �� �����Ѱ�(intŸ��)�� ȣ�Ⱑ�� �ϰ�, 
//						    ��ȯ���� bool�� ��ȯ �����ϸ� true

// std::predicate<F, int, int> : F�� ���� 2��(int, int)�� ������ �ΰ� ?

template<typename InputIter, typename Pred>
	requires std::predicate<Pred, std::iter_value_t< InputIter> >

InputIter myfind(InputIter first, InputIter last, Pred f)
{
	std::cout << "������(�Լ�) ����" << std::endl;
	return first;
}

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	auto p1 = myfind(std::begin(v), std::end(v), 3);
	auto p2 = myfind(std::begin(v), std::end(v), [](int a) { return a % 3 == 0; });

	/*
	std::sort(v.begin(), v.end());
	std::sort(v); // ��!! STL ���� �����̳ʸ� ���� ������ ������ ������ ??
				// => ����� �������ϴ�

	// �Ʒ� ������ ������ ������
	std::sort(v, ���Լ�����);		// ���ڰ� 2���� ���ø�
	std::sort(v.begin(), v.end());	// ���ڰ� 2���� ���ø�
							// => �ᱹ ����� ��� ���ڰ� 2���� ���ø��Դϴ�.
							// => �׷��� ����� �������ϴ�.
							// => ������ C++20 ���ʹ� �����̳� ���� �ֽ��ϴ�.
							//		=> ����!!!
	*/
}