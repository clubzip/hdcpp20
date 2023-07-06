#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <ranges>

int main()
{
    std::string s = "hello";

    auto p1 = std::ranges::begin( std::vector{1,2,3} ); 
                        // => 자원을 소유하는 컨테이너가 임시객체를 전달하는 경우
                        // => 컴파일 에러

    auto p2 = std::ranges::begin(std::string_view{ s });
                        // => string_view 자체는 자원을 소유하지 않습니다
                        // => string_view 가 파괴 되어도.. 자원은 남아있으므로
                        // => 반환된 반복자는 유효한 반복자 입니다.

    // 핵심 : 어떤 "range" 가 자원의 소유자인지 ? 자원을 빌려서 사용하는지?
    //       가 중요합니다.

    // range : begin, end 를 가진 것(컨테이너, view)
}
