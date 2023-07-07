#include <iostream>

// C++20 format 라이브러리
#include <format>   // 문자열 포맷과 관련된 몇가지 함수(클래스)제공

// std::string std::format(std::string_view format_string, Args... args);

int main()
{
    int num = 42;
    std::string name = "John";

    std::string s1 = std::format("{}, {}", name, num);
    std::cout << s1 << std::endl; // "John", 42

    std::string s2 = std::format("{1}, {0}, {1}", num, name);
    std::cout << s2 << std::endl; // "John", 42, "John"

    double d = 3.14159;
    std::string s3 = std::format("{1:.2s}, {0:.2f}", d, name);
    std::cout << s3 << std::endl;  // Jo, 3.14

    // {} 안에 변수명을 직접 적을수 없나요 ? 
    // => C#, python, swift 등
    // => C++ 은 안됩니다.
//  std::string s3 = std::format("{name}, {d}", d, name);
}
// std::format 에 대한 다양한 예제는 "cppreference.com" 에 잘되어 있습니다.