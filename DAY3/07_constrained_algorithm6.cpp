#include <iostream>
#include <vector>
#include <string>

// step 4. 비교에 사용할 이항함수 전달

// 1. std::identity 는 이미 C++20 표준입니다.

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