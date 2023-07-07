#include <list>
#include <string>
#include <iostream>

class String : public std::string
{
public:
	using std::string::basic_string;

	~String() { std::cout << "~String" << std::endl; }
};

// �ٽ� : mymax �� ������ ��ȯ Ÿ���� �� ������ ������
// => ���� C++ ǥ���� "std::max"�� �Ʒ� ��� �Դϴ�.
template<typename T> 
const T& mymax(const T& a, const T& b)
{
	return a < b ? b : a;
}

int main()
{
//	String s1 = "AA";
//	String s2 = "BB";
//	const String& s3 = mymax(s1, s2); // ok.. ������ �ڵ��Դϴ�.

	// �ٽ� : �ӽð�ü�� ������ "���ʿ� ����Ű�� const reference" �� ���ؼ���
	//		  ����ɼ� �ֽ��ϴ�.
	//		  2�� �������� �ɼ� �����ϴ�.
	//		  �Ʒ� s3 �� ����Ҽ� �����ϴ�. "dangling" �Դϴ�.
	//        cppreference.com ���� "std::max" �˻�
	const String& s3 = mymax(String("AA"), String("BB")); // ?

	std::cout << "==========" << std::endl;

	std::cout << s3 << std::endl;

	std::cout << "finish main" << std::endl;
}