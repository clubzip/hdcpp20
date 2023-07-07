#include <iostream>

// ���� C++ ǥ�� ������ �Ʒ� �ڵ� �Դϴ�.

template<typename T = void >	
struct plus
{
	[[nodiscard]] constexpr 
	const T& operator()(const T& a, const T& b) const noexcept
	{
		return a + b;
	}
};

// plus<void> ������ "C++11 �� �Ϻ��� ����" �� ���� �˴ϴ�.
template<>
struct plus<void>
{
	template<typename T1, typename T2>
	[[nodiscard]] constexpr 
	auto operator()(T1&& a, T2&& b) const noexcept
	{
		return std::forward<T1>(a) + std::forward<T2>(b);
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