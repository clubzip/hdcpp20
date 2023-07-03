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
// => ���ڰ� lvalue �ΰ��� rvalue ��쿡 T�� �ٸ��� �߷�

// n (lvalue) => T=int&,   T&&=int&
// 10(2value) => T=int,    T&&=int&&

template<typename T> int foo(T&& arg)
{    
    // template �ν��Ͻ�ȭ�� ����� ��Ȯ�� �˰� �ʹ�.

    print_info(); // ������ �Լ� �̸��� Ȯ���� ���� �ֽ��ϴ�.

    return 0;
}

int main()
{
    int n = 10;
    foo(n);
    foo(10);
}