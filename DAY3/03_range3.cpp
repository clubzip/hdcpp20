#include <vector>
#include <iostream>

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
class reverse_view
{
	T& rng;
public:
	reverse_view(T& r) : rng(r) {}
	auto begin() { return rng.rbegin(); }
	auto end()   { return rng.rend(); }
};

int main()
{
	std::vector v = { 1,2,3,4,5,6,7,8,9,10 }; // vector 는 자원 소유

	take_view tv(v, 5); 
	reverse_view rv(v); // 만들어 보세요

//	for (auto e : v)
//	for (auto e : tv)
	for (auto e : rv) // 10,9,8,7,6,5,4,3,2,1
		std::cout << e << ", ";

	std::cout << std::endl;


}