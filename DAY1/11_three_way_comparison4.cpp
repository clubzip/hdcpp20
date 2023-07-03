#include <iostream>
#include <cmath>
#include <compare> // std::strong_odering 

// <=> �������� ��ȯ Ÿ��
// ==> 0 ���� ũ�Ű�, ���ų�, �۴�.
// 1. std::strong_ordering : �ΰ��� ��Ұ� "����"�� ���Ҷ� ������ Ÿ��
// 2. std::weak_ordering   : �ΰ��� ��Ұ� "�����"�� ���Ҷ� ������ Ÿ��
// 3. std::partial_ordering : �ΰ��� ��Һ� �Ҽ��� ������, �񱳵ɼ� �������� ������

int main()
{
	// �ٽ� 1. ������ <=> �����ϸ� std::strong_ordering �� ��ȯ �˴ϴ�.
	// => 0 ���� ũ�Ű�, ���ų�, �۴�.
	auto ret1 = (3 <=> 4);

	// �Ʒ� 2���� ������ �ǹ�.
	if (ret1 > 0) {}
	if (ret1 == std::strong_ordering::greater) {}


	// �ٽ� 2. �Ǽ��� "NAN(Not An Number)" ��� ������ �ֽ��ϴ�.
	// "sqrt(����)" �� ����� NAN �Դϴ�.
	// => �׷��� <=> �� ����� 
	// => 0����, ũ�ų�, ���ų�, �۰ų�, �� �Ҽ� ���� �Դϴ�.
	// => ��ȯ Ÿ���� std::partial_odering �Դϴ�.

	auto ret2 = 1.2 <=> 3.4;		   // �Ǽ� <=> �Ǽ�
	auto ret3 = 1.2 <=> std::sqrt(-2); // �Ǽ� <=> NaN
	
	if (ret2 < 0) {}
	if (ret3 == std::partial_ordering::unordered ) 
	{
		std::cout << "���Ҽ� ����" << std::endl;
	}
}