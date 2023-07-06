#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector v = { 1,2,3,1,2,3,1,2,3,1 };

	// C++98 : erase-remove idioms 
	// STL �˰����� "�ڽ��� � �����̳ʿ� �����ϴ���" �˼� �����ϴ�.
	// => �׷���, �Ʒ� remove �� 3�� ������ ���� ��Ҹ� ������ �ű�� �˴ϴ�.
//	auto p = std::remove(v.begin(), v.end(), 3);

	// �����̳� ��ü�� ���̷��� "�Ϲ�ȭ�� �˰���(����� �ƴ� �Լ�)" �� �ƴ϶�
	// �����̳� ��ü�� ��� �Լ��� ����ؾ� �մϴ�.
//	v.erase(p, v.end());

	// �� ����� ���� �Ʒ� ó�� ���ٷ� �ϰ� �߽��ϴ�.
	// => �Ʒ� �ڵ带 ���� "erase-remove" ��� �ҷ����ϴ�.
//	v.erase( std::remove(v.begin(), v.end(), 3), v.end());
	
	// C++20 ������ ���� �����̳ʸ� ���ϼ� �ִ� std::erase() �� ���Խ��ϴ�.
	// ���� : erase(vector)
	//		 erase(list)
	//       erase(deque) ������ ��� �����̳ʿ� ���� �����ε��Ѱ�
	std::erase(v , 3);

	for (auto n : v) 
		std::cout << n << ", ";

	std::cout << std::endl;
}
