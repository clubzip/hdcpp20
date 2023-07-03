#include <compare>
#include <iostream>


// �ٽ� 1. operator<=> �� "= default" �� ��û�ϸ�
// => "����� ���� �������, ��� ����� ���ؼ� <=> �������� ��"
// => �Ʒ� ���� ���� ������ ������ ����
// => �� ���, "==" �����ڸ� ������ ������ �ʿ� �����ϴ�.

// �ٽ� 2. operator<=> �� ����ڰ� ����� ���
// => "operator==" �� �ݵ�� �����ؾ� �մϴ�.
// => "operator==" �� ��κ� <=> �ʹ� �ٸ��� ����ȭ �Ҽ� �ֱ� ������






class Point3D
{
    int x;
    int y;
    int z;
public:
    Point3D(int x = 0, int y = 0, int z = 0) : x{ x }, y{ y }, z{ z } {}



    // �ٽ� 1. <=> ������ �����ϱ�
    // => ��� �� ����, �� ��å�� �ᱹ ����ڰ� �����ؾ� �մϴ�.
    auto operator<=>(const Point3D& other) const
    {
        // C++17 init if ���� �Դϴ�.
        // if ( �񱳹� )
        // if ( �ʱ�ȭ; �񱳹� ) - C++17
        if (auto ret = (x <=> other.x);  ret != 0)
            return ret;

        else if (auto ret = (y <=> other.y);  ret != 0)
            return ret;

        // �� �κ� ���� ����Ȱ��� x == other.x, y = other.y �ΰ���Դϴ�.
        return z <=> other.z;
    }
    
    // �ٽ� 2. <=> �� ����ڰ� ���� ������ ���, == �����ڵ� �ݵ�� �����ؾ� �մϴ�.
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
