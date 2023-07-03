#include <iostream>
#include <algorithm>
#include <numeric>
#include <array>

// STL �� ���� �˰��� �� "constexpr"
// => ���� ���� STL �˰����� "������ �ð��� ��밡��" �������ϴ�.

int main()
{
//	constexpr int c = exp; // exp �� ����� "�ݵ�� ������ �ð��� �˾ƾ� �Ѵ�"�� ��

	constexpr int x[10] = { 1,2,3,4,5,6,7,8,9,10 };

	constexpr int c = std::accumulate(std::begin(x), std::end(x), 0);
				

	// ��, find �� ������ �ð� ���� �ȵ˴ϴ�
	constexpr auto p = std::find(std::begin(x), std::end(x), 5); // error
}
