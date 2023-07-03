#include <iostream>
#include <source_location>


void print_info(std::source_location location = std::source_location::current())
{
    std::cout << "file     : " << location.file_name() << std::endl;
    std::cout << "function : " << location.function_name() << std::endl;
    std::cout << "line     : " << location.line() << std::endl;
    std::cout << "column   : " << location.column() << std::endl;
}

// C++11 forwarding reference
// => 인자가 lvalue 인경우와 rvalue 경우에 T가 다르게 추론

// n (lvalue) => T=int&,   T&&=int&
// 10(2value) => T=int,    T&&=int&&

template<typename T> int foo(T&& arg)
{    
    // template 인스턴스화의 결과를 정확히 알고 싶다.

    print_info(); // 생성된 함수 이름을 확인해 볼수 있습니다.

    return 0;
}

int main()
{
    int n = 10;
    foo(n);
    foo(10);
}