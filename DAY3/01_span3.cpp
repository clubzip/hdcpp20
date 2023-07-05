#include <iostream>
#include <vector>
#include <span>

// string_view(C++17) : 문자(char)타입에 대한 연속된 메모리를 가리키는 view
// span(C++20)        : 임의타입에       대한 연속된 메모리를 가리키는 view
//                      string_view 의 generic 버전
//void foo(int* arr)  // 주소만 받게 됩니다.
void foo(std::span<int> sp) // 주소 와 길이를 모두 받게 됩니다.
{
    std::cout << sp.size() << std::endl;  // 10
}

int main()
{
    std::vector<int> v1 = { 1,2,3,4,5 };

    // 핵심 1. span 은 string_view 의 generic 버전
    std::vector<int> v2 = v1; // 버퍼를 복사 하게 됩니다.
    std::span<int>   sp = v1; // v1 버퍼에 대한 view 입니다.
    
    // 핵심 2. span 은 연속된 메모리는 어떠한 것도 가리킬수 있습니다.
    int arr[3] = { 1,2,3 };
    std::span<int> sp2 = arr;  // sp2 는 "arr주소 + 크기"

    // 핵심 3. span 은 쓰기 가능합니다.
    // => 참고 : string_view 는 읽기만 가능..!
    sp2[0] = 20;
    std::cout << arr[0]     << std::endl; // 20
    std::cout << sp2.size() << std::endl; // 3


    // 핵심 4. 배열을 함수로 전달할때
    // => int* 로 받으면, 주소와 길이를 같이 받아야 합니다.
    // => std::span 으로 받는 것이 편리합니다.

    int x[10]{1,2,3,4,5,6,7,8,9,10};
    // std::vector<int> x{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    foo(x);
}