#include <iostream>
#include <vector>
#include <list>
#include <iterator>


template<typename T> struct container_traits
{
	using value_type = typename T::value_type;
};

// raw array 를 위한 부분 특수화
template<typename T, int N> struct container_traits<T[N]>
{
//	using value_type = T;	// 2차 배열(ex, int[3][2]) 였다면
							// T=int[3]
	using value_type = std::remove_all_extents_t<T>;
};

template<typename T>
void container_type(T& c)
{	
//	typename T::value_type n1; // T가 배열이면 error
	typename container_traits<T>::value_type n2;
	std::cout << typeid(n2).name() << std::endl;
}

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	int x[3] = { 1,2,3 };
	int y[3][2] = {1,2,3,4,5,6};
	container_type(v);
	container_type(x);
	container_type(y);

}










