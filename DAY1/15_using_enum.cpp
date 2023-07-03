#include <string_view>

// using enum

// C++98 enum : "COLOR::" 없이 사용가능합니다.
//enum COLOR { RED, GREEN, BLUE };  


// C++11 scoped enum : 타입 강화, 반드시 "COLOR::" 과 같이 사용해야 합니다.
enum class COLOR { RED, GREEN, BLUE };

std::string_view to_string(COLOR color)
{
    switch (color)
    {     
        using enum COLOR;   // C++20 의 새로운 문법
                            // using namespace 와 유사한 개념
        case RED:   return "red";
        case GREEN: return "green";
        case BLUE:  return "blue";
    }
    return "invalid color";
}

int main()
{
//  std::string_view ret = to_string(RED);  // "COLOR::RED" 에서
                                            // "COLOR::" 없이 사용
                                            // C++98 스타일 enum 만 가능
                                            // C++11의 새로운 enum 은 "COLOR::"필요
    std::string_view ret = to_string(COLOR::RED); // ok. 
}
