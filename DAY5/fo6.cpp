#include <iostream>

// C++14 ���� std::plus �� �Ʒ� ó�� ����Ǿ����ϴ�.

//template<typename T >			// C++98 �� �� �ڵ尡
template<typename T = void >	// C++14 ���� �̷��� ����
struct plus
{
	inline const T& operator()(const T& a, const T& b) const
	{
		return a + b;
	}
};

// plus<void> ó�� ����Ҷ��� ������ �����մϴ�.
// => ��, ������ plus ����ڰ� void �� ���� ���� ���� �״�, 
// => ���ο� ������ plus<void> �������� ����
template<>
struct plus<void>
{
	template<typename T1, typename T2>
	inline auto operator()(const T1& a, const T2& b) const
	{
		return a + b;
	}
};

int main()
{
	plus<int> p1;	// int + int �� ����
	plus<void> p2;	// T1 + T2

	plus<> p3;		// T=void �̹Ƿ� plus<void> �� ����

	plus p3;		// C++17 ���� Ÿ�Կ� ����Ʈ ���� ������
					// <> ��ü�� ���������մϴ�.

	auto ret1 = p2(1, 3.4);

}