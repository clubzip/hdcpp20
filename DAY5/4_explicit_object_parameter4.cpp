#include <iostream>
#include <functional>

// deducing this 장점 3. recursive lambda 

int main()
{
    // 람다 표현식을 재귀 호출로 만들수 있을까요 ?
    // => 아래 코드는 에러 입니다.
//  auto factorial = [](int n) { return n > 1 ? n * factorial(n - 1) : 1;};

    // 아래 처럼 하면 됩니다.
    // => 람다표현식 변수를 다시 인자로 전달하는 것
//    auto factorial = [](int n, auto& factorial) { return n > 1 ? n * factorial(n - 1, factorial ) : 1; };
    
//    int n = factorial(5, factorial); // ok.. 
                          // 하지만 자신을 다시 인자로 보내므로 보기좋지는 않습니다.

//    std::cout << n << std::endl;

       
    // C++23 의 explicit object parameter 를 사용하면 간단하게 해결됩니다.
    // 핵심 1. 람다표현식은 결국 "operator()" 멤버 함수 입니다.
    //        즉,  [](int n) {} <= 이부분이 멤버 함수라는 의미

    auto factorial = [](this auto& self, int n) -> int { return n > 1 ? n * self(n - 1) : 1; };
    
    int n = factorial(5);
            // factorial.operator()(5) 입니다. operator() 멤버 함수 호출!
            // operator()(factorial, 5)
}

// explicit object parameter 를 사용하면
// 1. const, non-const member 함수를 하나의 함수(템플릿)으로 제공가능
// 2. CRTP 기술을 캐스팅 없이 사용가능
// 3. recursive 람다 표현식을 간결하게 만들수 있다.