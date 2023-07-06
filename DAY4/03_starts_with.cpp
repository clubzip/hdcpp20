#include <string>
#include <string_view>

// C++20 �����̳��� ��ȭ
// 1. std::string �� std::string_view �� ���ο� ��� �Լ�
int main()
{
	std::string str{ "example.cpp" };
	std::string_view sv{ str };

	// �ٽ�. starts_with()/ends_with() ��� �Լ� �߰�

	bool b1 = str.starts_with("sa"); // false
	bool b2 = str.ends_with(".cpp"); // true
	bool b3 = sv.starts_with("sa");  // false
	bool b4 = sv.ends_with(".cpp");  // true
}
