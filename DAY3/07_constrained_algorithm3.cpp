#include <iostream>
#include <vector>
#include <string>

// step 2. projection µµ¿‘

template<typename T, typename Projection >
const T& Max(const T& a, const T& b, Projection proj )
{
	return proj(a) < proj(b) ? b : a;
}

int main()
{
	std::string s1 = "ABC";
	std::string s2 = "XX";

	auto ret = Max(s1, s2, 
		[](const std::string& s) { return s.size(); } );

	std::cout << ret << std::endl; // "XX"
}