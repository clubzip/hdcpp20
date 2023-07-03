#include <iostream>
#include <string_view>
#include <source_location>

// "line ��ȣ : �޼���" ���·� �α� �Ϸ��� �Ѵ�.
// ��ũ�� : �����Ϸ��� ����Ǳ� ���� ��ó���Ⱑ ó�� �մϴ�.
void log1(std::string_view msg, int line = __LINE__) // ��ó���Ⱑ 
{													 // int line = 7�� ����		
	std::cout << line << " : " << msg << std::endl;
}


void log2(std::string_view msg, 
	      std::source_location loc = std::source_location::current() ) 
{													 
	std::cout << loc.line() << " : " << msg << std::endl;
}

int main()
{
	log1("message1", __LINE__); // 15 : message1
	log1("message2", __LINE__); // 16 : message2
	log1("message1");			// 17 : message3 �� ��������
	log1("message2");			// ���� ����� �׻� line �� 7 �Դϴ�.


	log2("message1", std::source_location::current() );		
	log2("message2");
}




