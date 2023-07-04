#include <iostream>
#include <algorithm>
#include <concepts>
#include <vector>



template<typename InputIter, typename T>
InputIter find(InputIter first, InputIter last, const T& value)
{
	std::cout << "�� ����" << std::endl;
	return first;
}

// �Ʒ� ó�� �߾�� �ϴµ�.. 
// �ᱹ �� ���ø��� ����� �����մϴ�.
// => error.
// => �׷���, find ��� ���� �̸��� ����Ҽ� ������, find_if �� �߽��ϴ�.
template<typename InputIter, typename Pred>
InputIter find(InputIter first, InputIter last, Pred f)
{
	std::cout << "������(�Լ�) ����" << std::endl;
	return first;
}




int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	
	// find    : �־��� �������� "��" �˻�
	// find_if : �־��� �������� ���� �˻�(������ ���ڷ� ȣ�Ⱑ���� ��ü(callable object) ����)
//	auto p1 = std::find   (std::begin(v), std::end(v), 3);
//	auto p2 = std::find_if(std::begin(v), std::end(v), [](int a) { return a % 3 == 0; } );

	// �׷���, �� 2�� �˰����� ���� �̸� (find) �� ������ ����� ?
	auto p1 = std::find(std::begin(v), std::end(v), 3);
	auto p2 = std::find(std::begin(v), std::end(v), [](int a) { return a % 3 == 0; });

}