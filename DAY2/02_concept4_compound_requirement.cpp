#include <iostream>
#include <concepts>

template<typename T> 
concept C2 = requires(T x)
{
    // T 타입의 객체에는 + 1 이 가능해야 한다.
    x + 1;      

    // 연산(함수호출)의 결과도 조건에 포함시키는 방법
//  { x + 1 } -> int;   // error. 타입을 직접 적으면 안되고!!
                        // concept 으로 표현해야 합니다.
    { x + 1 } -> std::same_as<int>; // ok. 결과가 int 이어야 한다.
                        // => 핵심, same_as 의 타입인자는 원래 2개인데..
                        //    이 위치에 표현할때는 인자가 1개로 
                        // std::same_as<x+1의결과타입, int>

    // C++ 진영에서는 "same_as" 보다는 "convertible_to" 를 권장 합니다
    // => "int 이어야 한다" 가 아니라
    // => "int로 변환 가능해야 한다" 의 의미.
    // =>  std::convertible_to<x+1의결과타입, int>
    {x + 1} -> std::convertible_to<int>;
};



int main()
{

    // 2개의 타입이 같은지 조사하는 방법
    // 1. traits 사용
    bool b1 = std::is_same_v<int, int>;    // true
    bool b2 = std::is_same_v<int, double>; // false

    // 2. concept 사용 => C++ 표준이 제공하는 미리 만들어진 concept 이 있습니다.
    bool b3 = std::same_as<int, int>; // true
                            // 실제 구현 원리는 std::is_same_v 사용
}