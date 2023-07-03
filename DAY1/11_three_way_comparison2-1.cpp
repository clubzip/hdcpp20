#include <compare>
#include <iostream>

class Point3D
{
    int x;
    int y;
    int z;
public:
    Point3D(int x = 0, int y = 0, int z = 0) : x{ x }, y{ y }, z{ z } {}

    auto operator<=>(const Point3D& other) const = default;
};

int main()
{
    Point3D p1{ 1,2,3 }, p2{ 3,2,1 };

    // 핵심 1. "rewrite expression" 개념
    // =>     사용자 코드            컴파일러가 변경한 코드(우주선 연산자를 사용하도록)
    bool b1 = p1 == p2;         // (p1 <=> p2) == 0
    bool b2 = p1 < p2;          // (p1 <=> p2) <  0
    bool b3 = p1 <= p2;         // (p1 <=> p2) <= 0

    auto ret = p1 <=> p2;

    // 결국 6개의 비교 연산자는 "우주선 연산자"로 모두 표현 가능합니다.
}
