#include <iostream>
#include <type_traits>
#include <vector>

// A. begin, end ��� �Լ��� ������ ��ȯŸ���� void �Դϴ�.
class A
{
public:
	void begin() {}
	void end() {}
};
// B. begin, end �� ��ȯŸ���� ������ �Դϴ�.
class B
{
public:
	int* begin() { return 0; }
	int* end()   { return 0; }
};



template<typename T>
concept container = requires(T & c)
{
	// �Ʒ� ó�� �����
	// 1. std::begin() �� ���ڷ� ������ �ְų�
	// 2. c.begin() �� �־ �˴ϴ�.
//	std::begin(c);  // �̼���, c.begin() �� �ٽ� ȣ���ϴ� ����
//	std::end(c);

	// ���� �����ϰ� �Ϸ���
	// "begin(), end() �� ��ȯ���� Ÿ���� �ݺ��� �̾�� �Ѵ�." 
	// ��� ������ �ʿ� �մϴ�.
	{ std::begin(c) } -> std::input_iterator;
	{ std::end(c) }   -> std::input_iterator;
};



template<typename T> void check(T& c)
{
	bool b = container<T>;
	std::cout << b << std::endl;
}

int main()
{
	std::cout << std::boolalpha;

	A aaa;
	B bbb;

	check(aaa);
	check(bbb);
}