#include <iostream>

// [[no_unique_address]]

// 핵심 1. empty class 알아 두세요.
// empty class : non-static 멤버데이타와 가상함수가 없는 클래스
//               sizeof(empty) == 1 입니다.(문법으로 약속)
struct Empty
{
    void foo() {} // 일반 멤버 함수는 있어도 empty 입니다.
};
Empty e;    // 아무 멤버도 없지만, 크기는 1입니다.

// 핵심 2. empty class 가 멤버 데이타로 놓이면 크기 계산에 포함됩니다.
struct Data1
{
    Empty e;
    int   n;
};

// 핵심 3. empty class 로 부터 상속 받으면 empty 는 크기로 계산 되지 않습니다.
// => EBCO : Empty Base Class Optimization 이라고 합니다.
struct Data2 : public Empty
{
    int   n;
};

// 핵심 4. C++20 [[no_unique_address]] attribute 를 사용하면
//        Empty 가 멤버로 있어도 크기에 포함되지 않습니다.
struct Data3
{
    [[no_unique_address]] Empty e;
    int   n;
};

int main()
{
    std::cout << sizeof(Empty) << std::endl; // 1
    std::cout << sizeof(Data1) << std::endl; // 8
    std::cout << sizeof(Data2) << std::endl; // 4
    std::cout << sizeof(Data3) << std::endl; // 4
}
// g++ 13.x : 지원
// visual studio 2022 : 지원안됨.
//                      [[no_unique_address]] 가 에러는 아님