#pragma once
#include <format>
#include <iostream>
#include <string_view>

// std::print 는 아래처럼 흉내낼수 있습니다.
// => 단, 내부적으로 cout 으로 하므로.. 느립니다.

template<class... Args>
inline void print(std::string_view fmt, const Args&... args)
{
    auto s = std::vformat(fmt, std::make_format_args(args...));
    std::cout << s;
}
template<class... Args>
inline void println(std::string_view fmt, const Args&... args)
{
    auto s = std::vformat(fmt, std::make_format_args(args...));
    std::cout << s << '\n';
}

int main()
{
    print("{0}, {1}\n", "kim", 20);
    println("{0}, {1}", "kim", 20);
}