#include <iostream>
#include <vector>
#include <string>

// step 2. projection ����

template<typename T, typename Projection >
const T& Max(const T& a, const T& b, Projection proj )
{
//	return proj(a) < proj(b) ? b : a;
	return std::invoke( proj, a) < std::invoke(proj, b) ? b : a;										// (b.*proj)()
}

int main()
{
	std::string s1 = "ABC";
	std::string s2 = "XX";

//	auto ret = Max(s1, s2, [](const std::string& s) { return s.size(); } );

	auto ret = Max(s1, s2, &std::string::size );

	std::cout << ret << std::endl; // "ABC"
}