#include <iostream>
#include <vector>
#include <string>

// step 3. projection 의 디폴트 값

template<typename T, typename Projection >
const T& Max(const T& a, const T& b, Projection proj)
{
	return std::invoke(proj, a) < std::invoke(proj, b) ? b : a;										// (b.*proj)()
}

int main()
{
	std::string s1 = "ABC";
	std::string s2 = "XX";
		
	auto ret = Max(s1, s2, &std::string::size);

	std::cout << ret << std::endl; 
}