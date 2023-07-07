#include <list>
#include <string>
#include <iostream>

class String : public std::string
{
public:
	using std::string::basic_string;

	~String() { std::cout << "~String" << std::endl; }
};

// 핵심 : mymax 의 인자의 반환 타입을 잘 생각해 보세요
// => 실제 C++ 표준의 "std::max"는 아래 모양 입니다.
template<typename T> 
const T& mymax(const T& a, const T& b)
{
	return a < b ? b : a;
}

int main()
{
//	String s1 = "AA";
//	String s2 = "BB";
//	const String& s3 = mymax(s1, s2); // ok.. 안전한 코드입니다.

	const String& s3 = mymax(String("AA"), String("BB")); // ?

	std::cout << s3 << std::endl;
}