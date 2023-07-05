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
	auto end() { return rng.begin() + sz; }
};

template<typename T>
take_view<T> take(T& c, std::size_t sz)
{
	return take_view<T>(c, sz);
}
//-------------------
// Pipe line 지원하기
struct take_view_tag
{
	std::size_t count;
};
inline take_view_tag take(std::size_t sz)
{
	return take_view_tag{ sz }; // 생성자 없어도 이렇게 가능합니다.
}
template<typename T>
inline take_view<T> operator | (T& c, take_view_tag tag)
{
	return take_view<T>(c, tag.count);
}


int main()
{
	std::vector v = { 1,2,3,4,5,6,7,8,9,10 }; 

	// 방법 1. take_view 클래스를 직접 사용
	take_view tv1(v, 5); 

	// 방법 2. take_view 를 생성하는 도움 함수 제공
	auto tv2 = take(v, 5);

	// 방법 3. Pipe line 를 사용해서 take_view 생성
	auto tv3 = v | take(3); // v | take_view_tag <= take(3) 반환타입
							// operator|(v, take_view_tag)



//	for (auto e : v)
	for (auto e : tv3)
		std::cout << e << ", ";

	std::cout << std::endl;

}






/*
	// C++ 코딩 관례 : 클래스 템플릿을 직접 사용하기도 하지만,
	//				 객체를 만드는 함수를 호출해서 만들기도 합니다.
	std::tuple<int, double, char> tp1(1, 3.4, 'A');

	// => C++17 이전까지는 클래스 템플릿의 타입추론이 안되기 때문에 위처럼
	//    사용해야 합니다.
	//    이것을 편리하게 하기위해서 tuple 을 만드는 함수도 제공했습니다.
	//    함수 템플릿은 타입추론이 되므로.
	auto tp2 = std::make_tuple(1, 3.4, 'A');


*/