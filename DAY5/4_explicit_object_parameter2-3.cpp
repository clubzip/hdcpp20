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


	T& operator[](int idx) { return buff[idx]; }
};

int main()
{
	vector v(10, 3);

	// �ٽ� 1. operator[] ������ �˾� �μ���
	int n = v[0]; // v1.operator[](0)
	v[0] = 5;     // v1.operator[](0) = 5;


	// �ٽ� 2. ��� vector �� ���� vector
	vector v1(10, 3);
	const vector v2(10, 3);

	//	�Ǿ��ұ�� ?   ���ϴ°�		�������
	int n1 = v1[0];	//
	int n2 = v2[0];	//

	v1[0] = 5;		//
	v2[0] = 5;		// 
}

