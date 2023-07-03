
// C++11 constexpr 상수 : 반드시 초기값을 컴파일 시간에 알아야 하는 "상수".
// C++20 constinit     : 반드시 초기값을 컴파일 시간에 알아야 하는 "변수".
int value1 = 10;

constexpr int c1 = value1; // error
constexpr int c2 = 10;     // ok

constinit int c3 = value1; // error
constinit int c4 = 10;	   // ok


int main()
{
	c2 = 20; // error. c2 는 상수
	c4 = 20; // ok..   c4 는 변수!!

	// 즉, constinit 은 전역변수 앞에 붙여서..
	// 반드시 초기값을 컴파일 시간에 알아야 한다는 것!

	// => C++이 갈수록 템플릿 등을 많이 사용하게 되어서
	// => 컴파일 시간에 하는 것이 많아집니다.
	// => 그래서 컴파일 시간을 요구하는 문법이 점점 많아 집니다.
}
// C++11 : constexpr 도입
// C++20 : consteval, constinit 도입