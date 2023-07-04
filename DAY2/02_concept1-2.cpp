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
//	{ std::begin(c) } -> std::input_iterator;
//	{ std::end(c) }   -> std::input_iterator;

	// �� �ڵ� ��ſ� �Ʒ� ó�� �ص� �˴ϴ�.
	// std::begin(c) : c.begin()�� ��ȯ Ÿ���� ������������
	// std::ranges::begin(c) : c.begin()�� ��ȯ Ÿ���� iterator �� �ƴϸ�
	//						   ������ ����!! - ���� �ڼ��� ���� �˴ϴ�.
	//						   C++20 ���� ���Ӱ� ������ begin()
	std::ranges::begin(c); 
	std::ranges::end(c);
};

template<typename T> void check(T& c)
{
//	bool b = container<T>;
		
	// �̹� ǥ�ؿ� ���� container �� �����Ѱ��� �ֽ��ϴ�.
	// C++20 ���ʹ� "container" ��� ��� ���� "range" ��� �� ����մϴ�.
	// => �ǹ̴� ���� �ڼ���.. 

	// std::ranges  : namespace �̸�
	// range<T>     : concept �̸�.
	bool b = std::ranges::range<T>;

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