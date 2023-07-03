#include <string_view>

// using enum

// C++98 enum : "COLOR::" ���� ��밡���մϴ�.
//enum COLOR { RED, GREEN, BLUE };  


// C++11 scoped enum : Ÿ�� ��ȭ, �ݵ�� "COLOR::" �� ���� ����ؾ� �մϴ�.
enum class COLOR { RED, GREEN, BLUE };

std::string_view to_string(COLOR color)
{
    switch (color)
    {     
        using enum COLOR;   // C++20 �� ���ο� ����
                            // using namespace �� ������ ����
        case RED:   return "red";
        case GREEN: return "green";
        case BLUE:  return "blue";
    }
    return "invalid color";
}

int main()
{
//  std::string_view ret = to_string(RED);  // "COLOR::RED" ����
                                            // "COLOR::" ���� ���
                                            // C++98 ��Ÿ�� enum �� ����
                                            // C++11�� ���ο� enum �� "COLOR::"�ʿ�
    std::string_view ret = to_string(COLOR::RED); // ok. 
}
