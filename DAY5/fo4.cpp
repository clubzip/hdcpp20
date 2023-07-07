#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>	// �� �ȿ� �̹� less, greater �� �ֽ��ϴ�
						// C++98 ��������!!!~~

inline bool foo(int a, int b) { return a < b; }

int main()
{
	std::vector v = { 1,3,5,7,9,2,4,6,8,10 };

	std::sort(v.begin(), v.end()); // �⺻ ���� : ���� ����

	// �� �Լ� ��ü
	// 1. �Ϲ� �Լ� - foo �� �ζ��� ġȯ �ɼ� �����ϴ�. �����ϴ�.
	std::sort(v.begin(), v.end(), foo);

	// 2. �Լ� ��ü - cmp�� operator() �� �ζ��� ġȯ �˴ϴ�. - �����ϴ�.
	std::less<int> cmp;
	std::sort(v.begin(), v.end(), cmp);
}