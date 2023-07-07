#include <list>
#include <string>
#include <iostream>

class String : public std::string
{
public:
	using std::string::basic_string;

	~String() { std::cout << "~String" << std::endl; }
};

template<typename T> 
const T& asConst(const T& obj)
{
	return obj;
}


int main()
{
	// range-for �� �ӽð�ü �ֱ�
	// => ������ �ڵ� �Դϴ�.
	/*
	for (auto e : String("ABCD") )
	{
		std::cout << e << ", ";
	}
	*/

	// �Ʒ� �ڵ�� ���� ? "as_const" �� ���� QT �� �ִ� �Լ� �Դϴ�.
	// => �������� �ʽ��ϴ�.
	// => ���� �Ʒ� ó�� ������� ������
	for (auto e : asConst( String("ABCD") ) )
	{
		std::cout << e << ", ";
	}

	// C++23 : range-for �ȿ����� �ӽð�ü ������
	//		   for �� ����ɶ� ���� ��������!!
	//		   ��, �� �ڵ带 �����ϰ� ����

	// => ���� ��� C++ �����Ϸ��� ���� ���մϴ�.

} 