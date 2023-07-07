#include <iostream>
#include <ranges>
#include <vector>

template<typename T>
class vector
{
	T* buff;
	std::size_t sz;
public:
	vector(std::size_t sz, const T& value = T()) : sz(sz)
	{
		buff = new T[sz];
		for (int i = 0; i < sz; i++)
			buff[i] = value;
	}
	~vector() { delete[] buff; }


	      T& operator[](int idx)       { return buff[idx]; }


	// 아래 2줄의 차이점을 생각해 봅시다.
	// T 반환    : v[0] 번째 메모리에 있는 값 반환.      rvalue(임시객체)
	// const T& : v[0] 번째 메모리의 별명을 상수로 반환. lvalue
	const T& operator[](int idx) const { return buff[idx]; }

//		   T operator[](int idx) const { return buff[idx]; }
};


int main()
{
	const vector v(10, 3);

	// & 연산자는 lvalue 에만 사용가능합니다.
	// rvalue(임시객체)는 주소를 구할수 없습니다.
	std::cout << &v[0] << std::endl;


}
