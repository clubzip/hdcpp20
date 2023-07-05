#include <iostream>
#include <span>

int main()
{
    // 핵심 1. 아래 처럼 초기화는 안됩니다.
//  std::span<int> sp = { 1,2,3 }; // error


    // 핵심 2. 배열과 포인터
    int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
    
    int* p = new int[10] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; // C++11 부터 가능


    // 배열 이름 x : 배열이 사용하는 메모리 주소 + 배열의 크기 정보를 포함
    //              sizeof(x) => 40 바이트
    // 
    // 포인터이름 p : 메모리 주소 정보만 있음. 
    //              sizeof(p) => 4(32bit), 8(64bit)


    // 핵심 3. 배열로 span 을 초기화 할때
    std::span<int>     sp1(x);  // x 는 배열이 이름이므로 이렇게만 해도 sp1이 
                                // 크기 정보를 가지게 됩니다.
                                // => 크기 정보를 별도의 멤버 데이타에 보관
                                // => 따라서 sp1 의 멤버 = 포인터크기 + size_t크기
    
    std::span<int, 10> sp2(x);  // 템플릿 인자로 크기를 전달하면 
                                // 크기정보가 바로 코드에 포함( 코드안에 "10" 으로)
                                // => 크기 정보 보관할 필요 없다.

    std::span<int>     sp3(x, 10);
    std::span<int, 10> sp4(x, 10);

    std::cout << sizeof(sp1) << std::endl; // 포인터 크기 + size 변수 크기
    std::cout << sizeof(sp2) << std::endl; // 포인터 크기 
    std::cout << sizeof(sp3) << std::endl;
    std::cout << sizeof(sp4) << std::endl;

    // 핵심 4. 포인터로 초기화 할때
    // => 포인터 이름에는 크기 정보가 없습니다.
    // => 생성자 인자로 반드시 크기 정보를 보내야 합니다.
//  std::span<int>     sp5(p);  // error
//  std::span<int, 10> sp6(p);  // error
    std::span<int>     sp7(p, 10); // ok
    std::span<int, 10> sp8(p, 10); // ok


    // 핵심 5. 다양한 멤버 함수 들
    std::span<int>     sp11(x);  
    std::span<int, 10> sp12(x);  

    std::cout << sp11.extent << std::endl;
    std::cout << sp12.extent << std::endl;

    std::cout << sp11.size() << std::endl;
    std::cout << sp11.size_bytes() << std::endl;
    std::cout << sp12.size() << std::endl;
    std::cout << sp12.size_bytes() << std::endl;

//   int* p = x;
//  std::span<int> sp3(p);     
//  std::span<int> sp4(p, 10); 
}