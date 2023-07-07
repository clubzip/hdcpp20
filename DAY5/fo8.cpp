#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main()
{
	std::vector v = { 1,3,5,7,9,2,4,6,8,10 };

	// sort() �� ��å �����ϴ� ��.
	std::less<int> cmp;
	std::sort(v.begin(), v.end(), cmp); // �Լ� ��ü�� ���� ����

	std::sort(v.begin(), v.end(), std::less<int>() ); // �ӽð�ü�� ����

	std::sort(v.begin(), v.end(), std::less<void>()); // void ���� ���
	std::sort(v.begin(), v.end(), std::less<>());     // void ���� ���.

	std::sort(v.begin(), v.end(), std::less()); // void ���� ���. C++17 ����
	
	std::sort(v.begin(), v.end(), std::less{}); //() ��� {}�� ����
						// => ������ �̷��� �θ� ���

	// 3��° ���ڷ� ���� ǥ���� ����ص� ������(�ᱹ �Լ� ��ü�̹Ƿ� ���� ȿ��)
	// �̹� less �� �����Ƿ� std::less ����� �� ���մϴ�.
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; } );
}