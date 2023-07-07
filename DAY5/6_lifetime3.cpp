#include <list>
#include <string>
#include <iostream>

class String : public std::string
{
public:
	using std::string::basic_string;

	~String() { std::cout << "~String" << std::endl; }
};

template<typename T> 
const T& asConst(const T& obj)
{
	return obj;
}


int main()
{
	// range-for 에 임시객체 넣기
	// => 안전한 코드 입니다.
	/*
	for (auto e : String("ABCD") )
	{
		std::cout << e << ", ";
	}
	*/

	// 아래 코드는 어떨까요 ? "as_const" 는 실제 QT 에 있는 함수 입니다.
	// => 안전하지 않습니다.
	// => 절대 아래 처럼 사용하지 마세요
	for (auto e : asConst( String("ABCD") ) )
	{
		std::cout << e << ", ";
	}

	// C++23 : range-for 안에서의 임시객체 수명은
	//		   for 가 종료될때 까지 보장하자!!
	//		   즉, 위 코드를 안전하게 하자

	// => 아직 모든 C++ 컴파일러가 지원 못합니다.

} 