#include <vector>
#include <iostream>
#include <ranges>

// ref_view �� �ᱹ �����͸� Ŭ������ ���Ѱ�..
// �������� : �����͸� ���� ����ϸ� -> �� ���������
//           ref_view �� Ŭ���� �̹Ƿ� . ���� ����


// raw reference : ���� ����� ���ü�� ����Ǵ� ����
//					����, "�̵� �Ұ����� ����" ��� �մϴ�.

// ref_view : view �� ���� �̵������� ���� ��� �մϴ�.
//				(������ ������ ������)
//			  �ᱹ, (�̵�������) ���� �� �����ϸ� �˴ϴ�.

template<typename T> class ref_view
{
	T* src;
public:
	ref_view(T& cont) : src(&cont) {}

	auto begin() { return src->begin(); }
	auto end()   { return src->end(); }
	auto size()	 { return src->size(); }
};

int main()
{
	std::vector<int> v1 = { 1,2,3,4,5 };
	std::vector<int> v2 = { 1,2,3,4,5,6,7,8,9,10 };

	// 1. raw reference
//	std::vector<int>& r1 = v1;
//	std::vector<int>& r2 = v2;

	// 2. reference �� �ƴ� pointer ���
	// => ���Կ����, ���ü�Ǻ��簡 �ƴ� ����Ű�� �����Ͱ� �̵�.
	// => ��, r1 r2 ���� . �� �ƴ� -> �� �ؾ� �Ѵ�.
	// std::vector<int>* r1 = &v1;
	// std::vector<int>* r2 = &v2;


	// 3. ref_view ����. ���� ���� �ֽ��ϴ�.
	ref_view r1 = v1;
	ref_view r2 = v2;



	// �ٽ� : �Ʒ� �ڵ��
	// 1. ������ �̵��Ѵ�. ��, r1�� v2�� ����Ű�� �ȴ�.      => ������ �ƴ� �������� ���۹��
	// 2. ������ ����Ű�� ���� ���Եȴ�. ��, v1 = v2 �� �ȴ�. => C++ ������ ���� ���
	r1 = r2;

	// ����� ������ ������
	std::cout << v1.size() << std::endl;
	std::cout << v2.size() << std::endl;
	std::cout << r1.size() << std::endl;
	std::cout << r2.size() << std::endl;
}