#include <iostream>
#include <vector>
#include <string>

// step 3. projection �� ����Ʈ ��

// ���ڷ� ���� ���� �״�� ��ȯ�ϴ� �Լ�
// int foo(int a) { return a; }

// ��ó�� �Լ��� �ƴ� �Ʒ� ���� �Լ���ü�� �ؾ� "Ÿ���� ����Ʈ��"���� ����ϱ� ���մϴ�.
// identity : ���ڷ� ���� ���� �״�� ��ȯ �ϴ� �Լ� ��ü
//			  C++11 �� �Ϻ��� ���� ��� ���
struct identity
{
	template<typename T>
	constexpr T&& operator()(T&& arg) const noexcept
	{
		return std::forward<T>(arg);
	}
};
// identity f;
// auto ret = f(3.4); // ret �� 3.4  ��, ���ڰ� �ٽ� ��ȯ

template<typename T, typename Projection = identity >
const T& Max(const T& a, const T& b, Projection proj = {} )
{
	return std::invoke(proj, a) < std::invoke(proj, b) ? b : a;										// (b.*proj)()
}

int main()
{
	std::string s1 = "ABC";
	std::string s2 = "XX";
		
//	auto ret = Max(s1, s2, &std::string::size);
	auto ret = Max(s1, s2);

	std::cout << ret << std::endl; 
}