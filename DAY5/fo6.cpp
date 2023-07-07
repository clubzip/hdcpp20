#include <iostream>

template<typename T>
struct plus
{
	inline const T& operator()(const T& a, const T& b) const
	{
		return a + b;
	}
};

int main()
{
	plus<int> p;

	int n = p(1, 2);

	double d = p(1, 3.4); // 
}