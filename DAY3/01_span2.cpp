#include <iostream>
#include <string>
#include <string_view>	// C++17

// ���ڷ� ���� ���ڿ��� �б⸸ �ϰ� �ʹ�.
void f1(std::string s)        {}
	// => bad, call by value.  string ��ü�� ���纻 + ���ڿ� �ڿ� ��ü�� ����!!

void f2(const std::string& s) {}
	// => good. call by const reference


void f3(std::string_view   s) {}
	// => best. 
	// => string_view �� call by value ����Ģ�Դϴ�.


int main()
{
	std::string src = "to be or not to be";
	
	f1(src);
	f2(src); // ���ڷ� ������ ������ �Ѱ�, ���ڿ� ���ٽô� 2�� ����
	f3(src); // ������ + ����,           ���ڿ� ���ٽô� 1�� ����


	// const string& �� string_view �� �������� �Ʒ�ó�� ����Ҷ� �Դϴ�.
	f2("to be or not to be");
			// => const std::string& �� �䱸�ϴµ�, ���ڿ� literal ����!!
			// => C++ �����Ϸ��� "���ڿ� literal �� string �����ڿ� �����ؼ�"
			// => string �ӽð�ü�� �����ǰ� �˴ϴ�. �ӽð�ü�� �Լ��� ����
			// => �ӽð�ü�� ���鶧 ���ڿ��� ���� ���� �ǰ� �ǹǷ� ������� �߻�..!
	f3("to be or not to be");
			// => string_view �� ��� �޸��� ���ڿ��� �׳� ����Ű�� �˴ϴ�.
			// => ������� ����.
}