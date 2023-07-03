#include <iostream>
#include <cmath>
#include <compare> // std::strong_odering 

// <=> �������� ��ȯ Ÿ��
// 1. std::strong_ordering : �ΰ��� ��Ұ� "����"�� ���Ҷ� ������ Ÿ��
// 2. std::weak_ordering   : �ΰ��� ��Ұ� "�����"�� ���Ҷ� ������ Ÿ��
// 3. std::partial_ordering : �ΰ��� ��Һ� �Ҽ��� ������, �񱳵ɼ� �������� ������

int main()
{
	// �ٽ� 1. ������ <=> �����ϸ� std::strong_ordering �� ��ȯ �˴ϴ�.
	auto ret1 = (3 <=> 4);

	// �Ʒ� 2���� ������ �ǹ�.
	if (ret1 > 0) {}
	if (ret1 == std::strong_ordering::greater) {}

}