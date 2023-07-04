#include <iostream>
#include <type_traits>


// template 안에서 static_assert 를 사용하면
// => 조건을 만족하지 않으면 에러 발생!!

// C++20. require clauses 를 사용한 템플릿
// => 조건을 만족하지 않으면 사용하지 않겠다!!
// => 동일 이름의 다른 함수가 있다면 사용가능

// 용어 주의 하세요
// concept  만들때 requires : require expression(표현식)
// template 만들때 requires : require clauses(절)

// requires 뒤에는 - traits, concept 등이 모두 올수 있습니다.

template<typename T> requires std::is_integral_v<T>
T gcd(T a, T b)
{
	return 0;
}

double gcd(double a, double b)
{
	std::cout << "double" << std::endl;
	return 0;
}

int main()
{
	gcd(10, 4);
	gcd(3.4, 4.2);

	gcd(3.4f, 4.2f); 
}
