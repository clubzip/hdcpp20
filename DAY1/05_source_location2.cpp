#include <iostream>
#include <string_view>
#include <source_location>

// "line 번호 : 메세지" 형태로 로깅 하려고 한다.
// 매크로 : 컴파일러가 수행되기 전에 전처리기가 처리 합니다.
void log1(std::string_view msg, int line = __LINE__) // 전처리기가 
{													 // int line = 7로 변경		
	std::cout << line << " : " << msg << std::endl;
}


void log2(std::string_view msg, 
	      std::source_location loc = std::source_location::current() ) 
{													 
	std::cout << loc.line() << " : " << msg << std::endl;
}

int main()
{
	log1("message1", __LINE__); // 15 : message1
	log1("message2", __LINE__); // 16 : message2
	log1("message1");			// 17 : message3 을 원하지만
	log1("message2");			// 실제 결과는 항상 line 은 7 입니다.


	log2("message1", std::source_location::current() );		
	log2("message2");
}




