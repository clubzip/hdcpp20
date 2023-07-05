#include <iostream>
#include <string>
#include <string_view>	// C++17






// C++17 �� string_view �̾߱�. 
int main()
{
	std::string src = "to be or not to be";

	// �ٽ� 1. string vs string_view
	// string : �ڿ�(���ڿ�)�� ����
	// string_view : �ڿ��� ������(borrowed) ���
	std::string      ss1 = src; // ���� ����� ����
								// ���ڿ��� ���� �޸� ��ü�� ����

	std::string_view sv1 = src; // ������ �Ѱ� + ���ڿ� ���� ������ ����
								// sv1 �� �����Ͱ� src �� ���۸� ����Ű�� �ȴ�.
	//-------------------------------------------------------------------
	// �ٽ� 2. string_view �δ� �б⸸ �����մϴ�.
//	sv1[0] = 'c';    // error
	auto c = sv1[0]; // ok


	// �ٽ� 3. string_view �� ���ڿ� literal�� �ʱ�ȭ �ϴ� ���
	// ==> �̺κ��� �ٽ� �Դϴ�. "��Ȯ�� ������ �μ���"
	const char* p = "to be or not to be"; // C����� ���ڿ� ������

	std::string      ss2 = "to be or not to be";
						// => ���� �Ҵ��ؼ� ���ڿ� ��ü�� �����մϴ�.
						// => ss2 �� ���ڿ��� ����

	std::string_view sv2 = "to be or not to be";
						// => ��� �޸𸮿� �ִ� ���ڿ��� �׳� ����ŵ�ϴ�.
						// => C ����� ���ڿ� �����Ϳ� ���� ����
						// => const char* 

	// �ٽ� 4
	std::string_view sv3 = src; // sv3 �� src �� ���ڿ��� ������ ���
	std::string_view sv4 = "to be or not to be"; // ��� �޸��� ���ڿ�
											// �� ����Ű�� �������ǹ�
}








