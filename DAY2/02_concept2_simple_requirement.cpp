#include <iostream>
#include <type_traits>
#include <string>
#include <vector>
#include <algorithm>

// Concept 을 만드는 방법 1. Simple requirement

// 1. concept 을 만드는 기본 모양
// template<typename T>
// concept 원하는이름 = 컴파일시간에_결정될수있는_bool_값;


// ex1. bool literal 사용
template<typename T>
concept always_true = true;

bool b1 = always_true<int>; // 어떠한 타입을 넣어도 true 입니다.


// ex2. 컴파일시간에 호출가능한 함수
          bool f1() { return true; }
const     bool f2() { return true; }
constexpr bool f3() { return true; }
consteval bool f4() { return true; }
template<typename T> concept C1 = f1();
template<typename T> concept C2 = f2();
template<typename T> concept C3 = f3();
template<typename T> concept C4 = f4();






int main()
{

}