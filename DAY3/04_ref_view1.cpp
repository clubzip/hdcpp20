#include <vector>
#include <iostream>
#include <ranges>

// ref_view 는 결국 포인터를 클래스로 감싼것..
// 만든이유 : 포인터를 직접 사용하면 -> 로 사용하지만
//           ref_view 는 클래스 이므로 . 으로 접근


// raw reference : 대입 연산시 대상체가 복사되는 참조
//					흔히, "이동 불가능한 참조" 라고 합니다.

// ref_view : view 에 대한 이동가능한 참조 라고 합니다.
//				(원리는 포인터 이지만)
//			  결국, (이동가능한) 참조 로 생각하면 됩니다.

template<typename T> class ref_view
{
	T* src;
public:
	ref_view(T& cont) : src(&cont) {}

	auto begin() { return src->begin(); }
	auto end()   { return src->end(); }
	auto size()	 { return src->size(); }
};

int main()
{
	std::vector<int> v1 = { 1,2,3,4,5 };
	std::vector<int> v2 = { 1,2,3,4,5,6,7,8,9,10 };

	// 1. raw reference
//	std::vector<int>& r1 = v1;
//	std::vector<int>& r2 = v2;

	// 2. reference 가 아닌 pointer 라면
	// => 대입연산시, 대상체의복사가 아닌 가리키는 포인터가 이동.
	// => 단, r1 r2 사용시 . 이 아닌 -> 로 해야 한다.
	// std::vector<int>* r1 = &v1;
	// std::vector<int>* r2 = &v2;


	// 3. ref_view 사용시. 위에 구현 있습니다.
	ref_view r1 = v1;
	ref_view r2 = v2;



	// 핵심 : 아래 코드는
	// 1. 참조가 이동한다. 즉, r1이 v2를 가리키게 된다.      => 참조가 아닌 포인터의 동작방식
	// 2. 참조가 가리키는 것이 대입된다. 즉, v1 = v2 가 된다. => C++ 참조의 동작 방식
	r1 = r2;

	// 결과를 예측해 보세요
	std::cout << v1.size() << std::endl;
	std::cout << v2.size() << std::endl;
	std::cout << r1.size() << std::endl;
	std::cout << r2.size() << std::endl;
}