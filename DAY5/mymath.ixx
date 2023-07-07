// 기존, C/C++ 에서 라이브러리를 만드는 방식
// .c(.cpp) : 함수(클래스)의 구현부 작성
// .h       : 함수(클래스)의 선언부 작성

// => 라이브러리 사용자는 #include "헤더파일" 후 사용
// 단점 1. 컴파일 시간이 오래 걸린다.
// 단점 2. 헤더가 헤더를 include 하는 문제 발생
//        "include guard", "#pragma once" 기술 사용

// 대부분의 다른 언어는 헤더파일의 개념이 없습니다.


// 핵심 : C++20 모듈 개념 도입
// => 라이브러리 구축시 더 이상 헤더를 만들 필요 없습니다.
// => 컴파일 속도가 빨라집니다.
// => 그런데, 아직 많은 C++ 컴파일러가 "부분적으로만 지원" 합니다.


// 핵심 1. 모듈(라이브러리)의 확장자는 표준에서 명시하지 않습니다.
// => 컴파일러마다 다를수 있습니다
// => Visual Studio 는 .ixx 입니다.


// mymath.ixx
// 빌드 명령 : cl  math.ixx /c  /std:c++20
// 결과물		: mymath.obj    mymath.ifc

#include <iostream>

export module mymath;

// export 가 없는 경우. 
// 모듈 내부에서만 사용가능합니다
export int add(int a, int b)
{
	return a + b;
}
export class Point
{
	int x, y;
public:
	Point(int x, int y) :x(x), y(y) {}

	void print() const { std::cout << x << ", " << y << std::endl; }
};

