#include <list>
#include <string>
#include <iostream>

// String 
// 1. std::string ���� ��ӹ޾Ƽ� std::string �� ��� ����� ������ �ֽ��ϴ�.
// 2. �Ҹ��ڸ� ���� �ı��Ǵ� ������ �ľ��ϱ� ���� ��������ϴ�.

// => ���������� STL �� ���� �Ļ������� ������.!!(STL �� ����Ҹ��� �ƴմϴ�.)
// => �н��� �뵵 ������ Ȱ���ϼ���


class String : public std::string
{
public:
	// �Ʒ� ������ "�����ڸ� ���"�� �޶�� ���� �Դϴ�.
	// ���� : string �� �����Դϴ�. basic_string<> �� ��¥ �̸� �Դϴ�
	using std::string::basic_string; 
			// std::basic_string<char>::basic_string;

	~String() { std::cout << "~String" << std::endl; }
};

int main()
{
	/*
	{
		String s1 = "AA";
		std::cout << s1 << std::endl;

		std::cout << "in block" << std::endl;

	} // <-- s1 �ı�.. �Ҹ��� ȣ��˴ϴ�.

	std::cout << "out block" << std::endl;
	*/


//	String("aaa"); // �̸� ���� ��ü(�ӽð�ü). �̹����� ������ �ı� �˴ϴ�.


	// �ӽð�ü�� ��� ������ ����Ű�� ������ ����˴ϴ�.(lifetime extension)
	const String& r = String("aaa");
						// �ӽð�ü����, r �̶�� ������ ����Ű�Ƿ�
						// �ӽð�ü�� r�� �������� ����˴ϴ�.

	std::cout << "---------" << std::endl;
} // <-- ���⼭ r �ı�.