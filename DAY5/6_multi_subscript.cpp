#include <array>
#include <iostream>

// multi dimension subscript
// vs 2022 아직 지원 안됨
// g++13.1 지원.. 
// g++ 6_multi_subscript.cpp -std=c++23

template<typename T, std::size_t X, std::size_t Y, std::size_t Z>
class array3d
{
    std::array<T, X * Y * Z> data;
public:
    // C++23 부터 [] 연산자 만들때 인자를 여러개 받아도 됩니다.
    T& operator[](std::size_t x, std::size_t y, std::size_t z)
    {
        return data[z + y * Z + x * Y * Z];
    }
};

int main()
{    
    std::array arr = { 1,2,3,4,5 };
    arr[0] = 10; // arr.operator[](0) = 10


    // C++23 부터 [] 연산자 재정의시 인자를 여러개 보낼수 있습니다.
    array3d<int, 4, 3, 2> v;

    v[3, 2, 1] = 42;  // v.operator[](3,2,1)     
}