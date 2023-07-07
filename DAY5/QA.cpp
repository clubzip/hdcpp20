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
	const T& operator[](int idx) const { return buff[idx]; }

};


int main()
{
	const vector v(10, 3);


}
