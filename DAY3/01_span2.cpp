#include <iostream>
#include <string>
#include <string_view>	// C++17

// 인자로 받은 문자열을 읽기만 하고 싶다.
void f1(std::string s)        {}
	// => bad, call by value.  string 객체의 복사본 + 문자열 자원 자체도 복사!!

void f2(const std::string& s) {}
	// => good. call by const reference


void f3(std::string_view   s) {}
	// => best. 
	// => string_view 는 call by value 가원칙입니다.


int main()
{
	std::string src = "to be or not to be";
	
	f1(src);
	f2(src); // 인자로 받을때 포인터 한개, 문자열 접근시는 2번 참조
	f3(src); // 포인터 + 길이,           문자열 접근시는 1번 참조


	// const string& 와 string_view 의 차이점은 아래처럼 사용할때 입니다.
	f2("to be or not to be");
			// => const std::string& 를 요구하는데, 문자열 literal 전달!!
			// => C++ 컴파일러가 "문자열 literal 을 string 생성자에 전달해서"
			// => string 임시객체가 생성되게 됩니다. 임시객체를 함수에 전달
			// => 임시객체를 만들때 문자열이 힙에 복사 되게 되므로 오버헤드 발생..!
	f3("to be or not to be");
			// => string_view 가 상수 메모리의 문자열을 그냥 가리키게 됩니다.
			// => 오버헤드 없음.
}