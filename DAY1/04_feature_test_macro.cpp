#include <iostream>
#include <numbers>
#include <span>

// ���� ����ϴ� �����Ϸ��� Ư�� ������ �����ϴ� �� 
// Ȯ�� �ϴ� ���.
// => �� ���� ���� ���θ� Ȯ���ϴ� ��ũ�� ����
int main()
{
#ifdef __cpp_concepts
	std::cout << "support concepts" << std::endl;
#endif

#ifdef __cpp_modules
	std::cout << "support module" << std::endl;
#endif

	// ���̺귯�� ���� ����
#ifdef __cpp_lib_span
	std::cout << "support span library" << std::endl;
#endif
}
// cppreferece.com ���� "Feature Test Macro" ����