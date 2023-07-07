#include <list>
#include <string>
#include <iostream>

// String 
// 1. std::string 에서 상속받아서 std::string 의 모든 기능을 가지고 있습니다.
// 2. 소멸자를 만들어서 파괴되는 시점을 파악하기 위해 만들었습니다.

// => 실전에서는 STL 로 부터 파생받지는 마세요.!!(STL 은 가상소멸자 아닙니다.)
// => 학습의 용도 정도만 활용하세요


class String : public std::string
{
public:
	// 아래 한줄은 "생성자를 상속"해 달라는 문법 입니다.
	// 참고 : string 은 별명입니다. basic_string<> 이 진짜 이름 입니다
	using std::string::basic_string; 
			// std::basic_string<char>::basic_string;

	~String() { std::cout << "~String" << std::endl; }
};

int main()
{
	/*
	{
		String s1 = "AA";
		std::cout << s1 << std::endl;

		std::cout << "in block" << std::endl;

	} // <-- s1 파괴.. 소멸자 호출됩니다.

	std::cout << "out block" << std::endl;
	*/


//	String("aaa"); // 이름 없는 객체(임시객체). 이문장의 끝에서 파괴 됩니다.


	// 임시객체를 상수 참조로 가리키면 수명이 연장됩니다.(lifetime extension)
	const String& r = String("aaa");
						// 임시객체지만, r 이라는 참조가 가리키므로
						// 임시객체가 r의 수명으로 연장됩니다.

	std::cout << "---------" << std::endl;
} // <-- 여기서 r 파괴.