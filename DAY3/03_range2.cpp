#include <vector>
#include <iostream>

// 핵심 : 아래 take_view 의 기능을 잘 생각해 보세요
template<typename T> 
class take_view
{
	T& rng;
	std::size_t sz;
public:
	take_view(T& r, std::size_t c) : rng(r), sz(c) {}

	auto begin() { return rng.begin(); }
	auto end()   { return rng.begin() + sz; }
};
int main()
{
	std::vector v = { 1,2,3,4,5,6,7,8,9,10 }; // vector 는 자원 소유

//	take_view<std::vector<int>> tv(v, 5); // 이렇게 사용하는 것이 정확한 표기법이지만
							// C++17 이후 부터는 클래스 템플릿도
							// 템플릿 인자 생략 가능합니다.
							// 생성자 인자를 통해서 타입 추론 가능

	take_view tv(v, 5); // 이 한줄을 잘생각해 보세요.
						// v를 5개 까지만 볼수 있는 시각(view) 를 제공

//	for (auto e : v)
	for (auto e : tv)
		std::cout << e << ", ";

	std::cout << std::endl;


}