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
	for (auto e : asConst( String("ABCD") ) )
	{
		std::cout << e << ", ";
	}

} 