#include <iostream>
#include <vector>
#include <ranges>

int main()
{
    // C++ 에서 객체의 종류
//  Point pt(1, 2); // 이름 있는 객체. 자신을 선언한 {} 을 벗어날때 파괴
//  Point (1, 2);   // 이름 없는 객체(임시객체), 문장의 끝에서 파괴
                    // => 단일 문장에서만 사용하는 객체


    // C++11 의 std::begin 에 컨테이너를 임시객체로 전달할때
    // => 임시객체는 "rvalue" 이므로 
    // => std::begin(const T&) 버전으로 받게 됩니다.
    // => 즉, 인자가 const & 이므로 반환되는 반복자는 const iterator 입니다.
    // => p1 을 쓰려고 하면 "컴파일 에러"
    // => p1 을 읽으려고 하면 "컴파일 에러" 는 아니지만, 잘못된 코드.
    auto p1 = std::begin(std::vector{1, 2, 3});
    
    std::cout << *p1 << std::endl;  // 버그..p1 이 가리키던 버퍼는 임시객체이므로 파괴
                                     
//  *p1 = 10; // error    


    // ranges::begin 은 임시객체를 전달하는 경우 - 컴파일 에러.
    auto p2 = std::ranges::begin(std::vector{1, 2, 3});
}

