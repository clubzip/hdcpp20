#include <iostream>
#include <vector>
#include <string>

// step 4. �񱳿� ����� �����Լ� ����

// 1. std::identity �� �̹� C++20 ǥ���Դϴ�.

template<typename T, typename CMP = std::less<void>, typename Projection = std::identity >
const T& Max(const T& a, const T& b, CMP cmp = {}, Projection proj = {})
{
//	return std::invoke(proj, a) < std::invoke(proj, b) ? b : a;		
	
//	return cmp( std::invoke(proj, a) ,  std::invoke(proj, b) ) ? b : a;

	return std::invoke( cmp, 
						std::invoke(proj, a), 
						std::invoke(proj, b) )  ? b : a;
}





int main()
{
	std::string s1 = "ABC";
	std::string s2 = "XX";

	//	auto ret = Max(s1, s2, &std::string::size);
	auto ret = Max(s1, s2);

	std::cout << ret << std::endl;
}