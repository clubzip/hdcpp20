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
	auto end() { return rng.begin() + sz; }
};

template<typename T>
take_view<T> take(T& c, std::size_t sz)
{
	return take_view<T>(c, sz);
}
//-------------------
// Pipe line �����ϱ�
struct take_view_tag
{
	std::size_t count;
};
inline take_view_tag take(std::size_t sz)
{
	return take_view_tag{ sz }; // ������ ��� �̷��� �����մϴ�.
}
template<typename T>
inline take_view<T> operator | (T& c, take_view_tag tag)
{
	return take_view<T>(c, tag.count);
}


int main()
{
	std::vector v = { 1,2,3,4,5,6,7,8,9,10 }; 

	// ��� 1. take_view Ŭ������ ���� ���
	take_view tv1(v, 5); 

	// ��� 2. take_view �� �����ϴ� ���� �Լ� ����
	auto tv2 = take(v, 5);

	// ��� 3. Pipe line �� ����ؼ� take_view ����
	auto tv3 = v | take(3); // v | take_view_tag <= take(3) ��ȯŸ��
							// operator|(v, take_view_tag)



//	for (auto e : v)
	for (auto e : tv3)
		std::cout << e << ", ";

	std::cout << std::endl;

}






/*
	// C++ �ڵ� ���� : Ŭ���� ���ø��� ���� ����ϱ⵵ ������,
	//				 ��ü�� ����� �Լ��� ȣ���ؼ� ����⵵ �մϴ�.
	std::tuple<int, double, char> tp1(1, 3.4, 'A');

	// => C++17 ���������� Ŭ���� ���ø��� Ÿ���߷��� �ȵǱ� ������ ��ó��
	//    ����ؾ� �մϴ�.
	//    �̰��� ���ϰ� �ϱ����ؼ� tuple �� ����� �Լ��� �����߽��ϴ�.
	//    �Լ� ���ø��� Ÿ���߷��� �ǹǷ�.
	auto tp2 = std::make_tuple(1, 3.4, 'A');


*/