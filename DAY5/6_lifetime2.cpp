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

	// 핵심 : 임시객체의 수명은 "최초에 가리키는 const reference" 에 의해서만
	//		  연장될수 있습니다.
	//		  2번 수명연장은 될수 없습니다.
	//		  아래 s3 는 사용할수 없습니다. "dangling" 입니다.
	//        cppreference.com 에서 "std::max" 검색
	const String& s3 = mymax(String("AA"), String("BB")); // ?

	std::cout << "==========" << std::endl;

	std::cout << s3 << std::endl;

	std::cout << "finish main" << std::endl;
}