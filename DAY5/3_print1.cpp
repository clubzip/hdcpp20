// C++20 : <format> �� ���ԵǾ����ϴ�.
// C++23 : <print>  �� ���ԵǾ����ϴ�.

// std::cout  ����
// 1. �ʹ� �����ϴ�.
// 2. �ڵ尡 �ʹ� ��Ȳ�մϴ�. ����� ������ ������ " << " �� �ʹ� ���� ����

// std::cout �� ������� ����ߴ��͵�
// 1. C ��� printf ��� ���
// 2. fmt ���̺귯��(���¼ҽ�) - ���� ������ ���,  std::print() ����

// C++23 
// => fmt ���̺귯���� �����ϰ� ���ο� ǥ�� ����� ��������ϴ�.
#include <print> // g++ 13.1 ���� ���� �ȵ�
				 // visual studio 17.7(preview ����) ���� ����
				 // ���� ���� �ֽ� ���� visual studio 17.6.4
#include <string>
#include <format>

int main()
{
	// ������ "std::format" �� �����մϴ�.
	// std::format : ������ ������ ���ڿ� �����
	std::string s = std::format("{0}, {1}", "kim", 20);

	// std::print : ������ ������ ȭ�� ���
	std::print("{0}, {1}\n", "kim", 20);
	std::println("{0}, {1}", "kim", 20);
}
