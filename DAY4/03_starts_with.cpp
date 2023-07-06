#include <string>
#include <string_view>

// C++20 컨테이너의 변화
// 1. std::string 과 std::string_view 의 새로운 멤버 함수
int main()
{
	std::string str{ "example.cpp" };
	std::string_view sv{ str };

	// 핵심. starts_with()/ends_with() 멤버 함수 추가

	bool b1 = str.starts_with("sa"); // false
	bool b2 = str.ends_with(".cpp"); // true
	bool b3 = sv.starts_with("sa");  // false
	bool b4 = sv.ends_with(".cpp");  // true
}
