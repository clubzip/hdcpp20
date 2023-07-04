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

//                                이부분이 컴파일시간에 bool 값으로 결정가능하면 ok
//template<typename T> concept C1 = f1(); // error ( 사용하면 에러 입니다. C1<int>)
//template<typename T> concept C2 = f2(); // error
template<typename T> concept C3 = f3(); // ok
template<typename T> concept C4 = f4(); // ok

//bool b2 = C1<int>; // error
bool b3 = C3<int>; // ok



// ex3. type_traits로 만들어도 됩니다.- 실제 많이 사용합니다.
// => 왜?? traits 를 사용하면 되는데, 다시 concept 을 만드나요 ?
// => traits 로 못하는 작업을 concept 으로 가능한 것이 있습니다.
//    (require caluse, syntax sugar 예제 참고)
template<typename T>
concept pointer = std::is_pointer_v<T>;

// 이제 포인터 인지 조사하는 2가지 방법
bool b4 = std::is_pointer_v<int>; // traits 를 직접 사용
bool b5 = pointer<int>;           // 위에서 만든 concept 사용


// ex4. && || 사용가능합니다
template<typename T>
concept signed_integer = std::is_integral_v<T> && std::is_signed_v<T>;

bool b6 = signed_integer<int>; // true



// ex5. require expression 사용
// => T의 타입 추론은 "함수템플릿" 과 같습니다.   ============> "타입추론" 참고
// => 즉, T a 일때 addable<int[3]> 으로 전달하면 T=int*
//    T& a 로 하면 addable<int[3]> 으로 전달시   T=int[3] 입니다.
template<typename T>
concept addable = requires(T a, T b) // => 이부분을 "require expression"
{                                    // => 이라고 합니다.
    a + b;
};

// ex6. 타입인자 여러개도 가능합니다.
template<typename T, typename U>
concept addable_two_type = requires(T a, U b) 
{                                    
    a + b;
};

class Point {};

int main()
{
    std::cout << addable<int> << std::endl;     // true
    std::cout << addable<Point> << std::endl;   // false 
    std::cout << addable_two_type<int, double> << std::endl; // true

}