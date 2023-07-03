#include <iostream>
#include <source_location>

int main()
{
	// C style => ��ũ��!
	std::cout << __FILE__ << std::endl; // ���� �̸�
	std::cout << __func__ << std::endl;	// ���� �Լ� �̸� - main
	std::cout << __LINE__ << std::endl; // line 

	// C++20 ���� �� ��ũ�� ������� ����, �Ʒ� ó�� �ϼ���
	std::source_location loc = std::source_location::current();

	// �Ʒ� ó�� ���� ������ �ƴ�����, ��ȿ���� ���� ���� ������ �˴ϴ�.
	// �� ��ó�� �ʱ�ȭ �ؼ� ����ϼ���
//	std::source_location loc2;

	std::cout << loc.file_name()     << std::endl;
	std::cout << loc.function_name() << std::endl;
				// => "main" �� ���ü��� �ְ�
				// => "int main(void)" ������ signature�� �����Ҽ��� �ֽ��ϴ�.
				// => C++ ǥ�ع������� "������ ���� �ٸ��� ����" �̶�� �Ǿ� �ֽ��ϴ�.

	std::cout << loc.line()			 << std::endl;

}
