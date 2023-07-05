#include <vector>
#include <iostream>

// �ٽ� : �Ʒ� take_view �� ����� �� ������ ������
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
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	take_view tv(v, 5); // �� ������ �߻����� ������.

	for (auto e : v)
		std::cout << e << ", ";

	std::cout << std::endl;


}