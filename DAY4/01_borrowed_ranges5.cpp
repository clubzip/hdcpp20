#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <algorithm>

int main()
{
    // std::ranges::begin 에 rvalue range(임시객체) 를 전달하는 경우

//  auto p = std::ranges::begin(std::vector{1, 2, 3});
                // => 인자가 borrowed range 라면 ok
                // => 인자가 borrowed range 가 아니면 error


    // std::ranges::begin 이 아닌
    // std::ranges 알고리즘에 rvalue range 를 전달하는 경우

    // 1. 반복자가 아닌 값을 반환하는 경우. 아무 문제 없다.
    auto n = std::ranges::min(std::vector{5, 4, 3, 1, 2, 9});
    std::cout << n << std::endl; // 


    // 2. 반복자를 반환하는 알고리즘에, borrowed_range 가 아닌 것의 임시객체전달
    // => std::ranges::dagling 이라는 타입으로 반환됨..
    // => std::ranges::dagling 타입은 * 연산 제공 안함, * 사용시 에러
    // => C의 dangling pointer 개념을 타입화 한것
    auto p1 = std::ranges::find(std::vector{1, 2, 3}, 2);
//  *p1 = 10;


    // 3. 반복자를 반환하는 알고리즘에, borrowed_range 의 임시객체전달
    std::string s{ "Hello" };
    auto p2 = std::ranges::find(std::string_view{s}, 'e');

    auto c = *p2; // ok.. 

}