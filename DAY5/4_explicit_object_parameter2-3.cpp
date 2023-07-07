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

	// vector �� [] �����ڴ� �ᱹ �Ʒ� ó�� 2�� ������ �մϴ�.
	// => C++ ���� ��ó�� ���� �̸��� �Լ��� "const", "non-const"��
	//    ��� �����ϴ� ��찡 ���� �����ϴ�
	//    v.begin() �� �Ʒ� ó�� 2�� ������ �մϴ�.
//	      T& operator[](int idx)       { return buff[idx]; }
//	const T& operator[](int idx) const { return buff[idx]; }


	/*
	// �� 2���� explicit object paramter �� �غ��ô�.
	T& operator[](this vector& self, int idx)
	{ 
		return self.buff[self.idx]; 
	}

	// �ٽ� : �Լ�() �ڿ� �ִ� const �� �Լ� ���ڰ� �Ǿ����ϴ�.
	const T& operator[](this const vector& self, int idx)
	{
		return self.buff[self.idx];
	}
	*/
	// �� 2�� �Լ��� ������ ������ �����ѵ� ������ Ÿ�Ը� �ٸ��ϴ�.
	// => ���ø����� �ϸ� �Ѱ��� �Լ���.. �� 2���� �ڵ����� �����մϴ�.
	template<typename U>
	auto& operator[](this U& self, int idx)
	{
		return self.buff[self.idx];
	}
	
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

	//	�Ǿ��ұ�� ?     ���ϴ°�		
	int n1 = v1[0];	// O
	int n2 = v2[0];	// O

	v1[0] = 5;		// O
	v2[0] = 5;		// X
}

