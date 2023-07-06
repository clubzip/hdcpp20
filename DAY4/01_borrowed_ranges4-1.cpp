#include <iostream>
#include <vector>
#include <ranges>
#include <string>
#include <string_view>

template<typename T> void check(T& c)
{
	std::cout << std::boolalpha;

	// �Ʒ� �ڵ�� "variable template" �� ���� ����ϴ� ��.
	std::cout << std::ranges::enable_borrowed_range<T> << std::endl;

	// �Ʒ� �ڵ�� "concept" �� ����ϴ� �� - ����
	// T�� 
	// => "ranges" �̰� "enable_borrowed_range �� true" ���� 2���� Ȯ��
	// �տ��� ���� borrowed_range concept �� �̹� ǥ�ؿ� �ֽ��ϴ�.
	std::cout << std::ranges::borrowed_range<T> << std::endl;

	
}

int main()
{
	std::vector v{ 1, 2, 3, 4, 5 };
	std::string s = "hello";
	int x[3] = { 1,2,3 };
	std::string_view sv = s;
	std::ranges::take_view tv(v, 3);

	check(v);	// false
	check(s);	// false
	check(x);	// false
	check(sv);	// true
	check(tv);	// true
}


