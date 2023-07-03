#include <type_traits>

template<typename T> class Value
{
	T value;
public:	
	// explicit 생성자 : C++98 문법
	//					직접 초기화면 가능하고 복사 초기화는 사용할수 없다.
//	explicit Value(T arg) {}

	// C++20 부터 조건부 explicit 가 지원 됩니다.
//	explicit(false) Value(T arg) {}
//	explicit(true) Value(T arg) {}

	// 실제로는 아래 처럼 T의 특징에 따라서 explicit 적용 여부를 결정할때 사용
	explicit(std::is_integral_v<T>) Value(T arg) {}
};

int main()
{
	// 
	Value v1{ 123 };	// direct initialization : = 이 없는 것
	Value v2 = { 123 };	// copy initialization   : = 이 있는 것

	Value v3{ 3.4 };
	Value v4 = { 3.4 }; // ok.. 실수 이므로 explicit 아님.
}
