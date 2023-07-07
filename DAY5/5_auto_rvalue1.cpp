#include <vector>
#include <iostream>
#include <algorithm>

// 아래 foo 는 결국 템플릿 입니다.
// 아래 코드 결과 예측해 보세요

void foo(auto& c)
{
	// c 안에서 c의 1번째 요소와 동일한 값을 제거하고 싶다.
	// 
	// c.front()        : 참조로 반환 합니다 ( T& )
	// remove 3번째 인자 : const T& 로 받아서 사용합니다.
	// => 즉, 어디서도 1번째 요소의 복사본을 만들지는 않습니다.

	// auto ret = std::remove(c.begin(), c.end(), c.front());


	// 해결책 : c.front() 를 인자로 사용하지 말고, 
	//		   c.front() 의 복사본을 만들어서 인자로 사용하면 됩니다.
	// 아래 코드는 아무 문제 없지만
	// => tmp 을 만들어야 한다는 것이 좋지 않습니다. 
	// => tmp 는 이름 있는 객체이므로 {} 벗어날때 까지 파괴되지 않습니다.
//	auto tmp = c.front();
//	auto ret = std::remove(c.begin(), c.end(), tmp);


	// 좀더 좋은 해결책
	// => c.front() 를 가지고 lvalue(이름있는 객체)를 만들지 말고
	//    rvalue(이름없는 객체, 임시객체)를 만들어 사용하는 것이 좋다.
	
//	auto ret = std::remove(c.begin(), c.end(), int( c.front() ) );



	// 그런데, 위 코드는 c.front() 가 int 타입이라고 가정한 코드 입니다.
	// => 위 코드를 모든 타입으로 일반화 하려면 ??
	// C++23 이전
	//using T = decltype(c.front()); // c.front()는 참조 반환이므로 int& 됩니다.

//	using T = std::decay_t<decltype(c.front())>; // const, reference 제거
//	auto ret = std::remove(c.begin(), c.end(), T(c.front()));

	// C++23 이후
	// auto(표현식) 또는 auto{표현식}
	// => 표현식과 같은 값을 가지는 prvalue 를 만드는 표현식
	// => 아래 예제에서는 auto(c.front()) 은 결국 literal 1 입니다.
	// => VS 아직 지원 못함. g++13.1 은 가능
	auto ret = std::remove(c.begin(), c.end(), auto{ c.front() } ) ;

	c.erase(ret, c.end());
}





int main()
{
	std::vector v{1, 2, 3, 1, 2, 3, 1, 2, 3, 1};

	foo(v);

	for (auto e : v)
		std::cout << e << ", ";

	std::cout << std::endl;
}