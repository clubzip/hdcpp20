#include <compare>
#include <iostream>


// 핵심 1. operator<=> 를 "= default" 로 요청하면
// => "멤버가 놓인 순서대로, 모든 멤버에 대해서 <=> 연산으로 비교"
// => 아래 직접 만든 구현과 동일한 원리
// => 이 경우, "==" 연산자를 별도로 제공할 필요 없습니다.

// 핵심 2. operator<=> 를 사용자가 만드는 경우
// => "operator==" 도 반드시 제공해야 합니다.
// => "operator==" 는 대부분 <=> 와는 다르게 최적화 할수 있기 때문에






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
