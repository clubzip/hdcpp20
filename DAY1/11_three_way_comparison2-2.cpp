#include <compare>
#include <iostream>

class Point3D
{
    int x;
    int y;
    int z;
public:
    Point3D(int x = 0, int y = 0, int z = 0) : x{ x }, y{ y }, z{ z } {}



    // 핵심 1. <=> 연산자 구현하기
    // => 어떻게 비교 할지, 비교 정책은 결국 사용자가 결정해야 합니다.
    auto operator<=>(const Point3D& other) const
    {
        // C++17 init if 구문 입니다.
        // if ( 비교문 )
        // if ( 초기화; 비교문 ) - C++17
        if (auto ret = (x <=> other.x);  ret != 0)
            return ret;

        else if (auto ret = (y <=> other.y);  ret != 0)
            return ret;

        // 이 부분 까지 실행된경우는 x == other.x, y = other.y 인경우입니다.
        return z <=> other.z;
    }
    
    // 핵심 2. <=> 를 사용자가 직접 구현한 경우, == 연산자도 반드시 제공해야 합니다.
    bool operator==(const Point3D& other) const
    {
        return x == other.x && y == other.y && z == other.z;
    }
};








int main()
{
    Point3D p1{ 1,2,3 }, p2{ 3,2,1 };

     bool b1 = p1 == p2; 
    bool b2 = p1 < p2;   
    bool b3 = p1 <= p2;  

    auto ret = p1 <=> p2;

}
