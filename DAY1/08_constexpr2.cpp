class Base
{
public:
	virtual int foo(int a, int b) { return a + b; }
};

class Derived : public Base
{
public:
	// C++20 부터 가상함수에도 constexpr 사용가능합니다.
	// constexpr : 컴파일 시간에 수행될 필요 있다면 컴파일 시간에 수행해 달라.
	constexpr int foo(int a, int b) override { return a + b; }
};

int main()
{
	// 가상함수 호출시 정확한 객체 이름으로 호출하면
	// "컴파일 시에 실행될수 있습니다."
	Derived d;					// d의 타입을 컴파일러가 알게 됩니다.
	int ret1 = d.foo(1, 2);		// 실행시간 호출
	constexpr int ret2 = d.foo(1, 2);	// 결과를 constexpr 에 담으므로 
										// d.foo()는 컴파일 시간이어야 합니다.
										// C++20 부터는 ok.


	Base* p = &d;				// 기반 클래스 포인터로 가상함수 호출시
	int ret3 = p->foo(1, 2);	// ok
//	constexpr int ret4 = p->foo(1, 2);	// error.
										// 가상함수 이므로 가상함수 테이블 사용해서
}										// 호출
