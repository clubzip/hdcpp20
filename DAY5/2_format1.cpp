#include <iostream>

// C++20 format ���̺귯��
#include <format>   // ���ڿ� ���˰� ���õ� ��� �Լ�(Ŭ����)����

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

    // {} �ȿ� �������� ���� ������ ������ ? 
    // => C#, python, swift ��
    // => C++ �� �ȵ˴ϴ�.
//  std::string s3 = std::format("{name}, {d}", d, name);
}
// std::format �� ���� �پ��� ������ "cppreference.com" �� �ߵǾ� �ֽ��ϴ�.