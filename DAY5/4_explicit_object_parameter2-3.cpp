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

	// vector 의 [] 연산자는 결국 아래 처럼 2개 만들어야 합니다.
	// => C++ 에서 이처럼 동일 이름의 함수를 "const", "non-const"로
	//    모두 제공하는 경우가 아주 많습니다
	//    v.begin() 도 아래 처럼 2개 만들어야 합니다.
//	      T& operator[](int idx)       { return buff[idx]; }
//	const T& operator[](int idx) const { return buff[idx]; }


	/*
	// 위 2개를 explicit object paramter 로 해봅시다.
	T& operator[](this vector& self, int idx)
	{ 
		return self.buff[self.idx]; 
	}

	// 핵심 : 함수() 뒤에 있던 const 가 함수 인자가 되었습니다.
	const T& operator[](this const vector& self, int idx)
	{
		return self.buff[self.idx];
	}
	*/
	// 위 2개 함수는 구현이 완전히 동일한데 인자의 타입만 다릅니다.
	// => 템플릿으로 하면 한개의 함수로.. 위 2개를 자동생성 가능합니다.
	template<typename U>
	auto& operator[](this U& self, int idx)
	{
		return self.buff[self.idx];
	}
	
};

int main()
{
	vector v(10, 3);

	// 핵심 1. operator[] 연산자 알아 두세요
	int n = v[0]; // v1.operator[](0)
	v[0] = 5;     // v1.operator[](0) = 5;


	// 핵심 2. 상수 vector 와 비상수 vector
	vector v1(10, 3);
	const vector v2(10, 3);

	//	되야할까요 ?     원하는것		
	int n1 = v1[0];	// O
	int n2 = v2[0];	// O

	v1[0] = 5;		// O
	v2[0] = 5;		// X
}

