#include <vector>
#include <string>
#include <numeric>

int main()
{
	// C++20 ���ʹ� vector �� constexpr ���� �ؾ� �Ѵٰ� �Ǿ� �ֽ��ϴ�.
	// �׷���.. ���� �����Ϸ��� ���� ���ϰ� �ֽ��ϴ�.
	
	// �Ϲ� vector : ��� ��Ұ� ���� ���̰� �˴ϴ�.
	// constexpr vector : ���� �ƴ� �ٸ� ������� �����˴ϴ�.
	//						�����Ϸ����� �ٸ�.
	constexpr std::vector v = { 1,2,3,4,5,6,7,8,9,10 };

	constexpr int c = std::accumulate(std::begin(v), std::end(v), 0);

}

// ��� 
// 1. C++20 ���� constexpr �� ���� ��ȭ �ǰ�
// 2. std::is_constant_evaluated() �� �����˴ϴ�.
