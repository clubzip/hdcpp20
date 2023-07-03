#include <compare>
#include <iostream>

class Point3D
{
    int x;
    int y;
    int z;
public:
    Point3D(int x = 0, int y = 0, int z = 0) : x{ x }, y{ y }, z{ z } {}

    // 사용자 정의 타입에 비교연산을 제공하려면
    // C++20 이전까지는 총 6개의 비교 연산자를 모두 제공(연산자 재정의)해야 합니다.
    // => 만드는 것은 어렵지 않지만 지루한 코드(boiler-plate) 입니다.

    // C++20 이후에는 <=> 한개만 아래 처럼 만들면 6개의 비교연산이 모두 지원됩니다.
    // => 그리고, "=default"로 지원 받을수도 있습니다.
    auto operator<=>(const Point3D& other) const = default;
};

int main()
{
    Point3D p1{ 1,2,3 }, p2{ 3,2,1 };

    // 사용자 정의 타입에 대해서 아래와 같이  비교 연산을 하고 싶다고 생각해 보세요.
    bool b1 = p1 == p2;
    bool b2 = p1 < p2;
    bool b3 = p1 <= p2;

    auto ret = p1 <=> p2;
}
