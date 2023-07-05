#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// C++20 ������ ������ �ִ� ��κ��� �˰����� �ٽ� ��������ϴ�.
// => std::ranges �ȿ� �ֽ��ϴ�.

int main()
{
	std::vector<std::string> v = { "banana", "apple", "pear", "orange" };

	// �ٽ� 1. �ݺ��� ���� vs �����̳� ����
//	std::ranges::sort(v.begin(), v.end()); // �ݺ��� ����
//	std::ranges::sort(v);				   // �����̳� ����

	// �ٽ� 2. �� �Լ� ��ü - C++98 �� ����
//	std::ranges::sort(v);  // �⺻ ���� : std::less ��� , < �� ��
//	std::ranges::sort(v, [](auto& s1, auto& s2) { return s1 > s2; });

//	std::ranges::sort(v, std::greater{} ); // ���� ����, > ������ �ϴ� �Լ���ü


	// �ٽ� 3. projection ���

//	std::ranges::sort(v, std::less{}, &std::string::size );  // less�� < ����
//	std::ranges::sort(v, {}, &std::string::size);  // {} �� �����ص� ��.
											// ����Ʈ Ÿ���� less�� �����Ǿ����Ƿ�

	std::ranges::sort(v, std::greater{}, &std::string::size);


	for (const auto& e : v)
	{
		std::cout << e << ", ";
	}

}