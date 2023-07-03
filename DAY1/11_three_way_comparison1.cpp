#include <iostream>


int main()
{
    int a = 10, b = 20;

    // 기존 C++ : 6개의 비교 연산자가 있습니다.
    //            ==, !=, <, <=, >, >=
    bool ret1 = a < b;

    
    // C++20 의 새로운 비교 연산자
    // 공식 명칭 : three way comparision operator
    // 별명      : spaceship operator(우주선 연산자)
    auto ret2 =   a <=> b;


    // 반환값은 0 보다 큰지, 작은지로 비교 합니다.
    if (ret2 > 0) // ret2 >= 0
        std::cout << "a > b" << std::endl;

    else if ( ret2 == 0 )
        std::cout << "a == b" << std::endl;

    else if (ret2 < 0)  // ret2 <= 0
        std::cout << "a < b" << std::endl;

    // 주의 ret2의 타입은 int 아닙니다.
    std::cout << typeid(ret2).name() << std::endl;
                        // => std::strong_ordering 라는 타입


}
