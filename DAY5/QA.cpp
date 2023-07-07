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


	// �Ʒ� 2���� �������� ������ ���ô�.
	// T ��ȯ    : v[0] ��° �޸𸮿� �ִ� �� ��ȯ.      rvalue(�ӽð�ü)
	// const T& : v[0] ��° �޸��� ������ ����� ��ȯ. lvalue
	const T& operator[](int idx) const { return buff[idx]; }

//		   T operator[](int idx) const { return buff[idx]; }
};


int main()
{
	const vector v(10, 3);

	// & �����ڴ� lvalue ���� ��밡���մϴ�.
	// rvalue(�ӽð�ü)�� �ּҸ� ���Ҽ� �����ϴ�.
	std::cout << &v[0] << std::endl;


}
