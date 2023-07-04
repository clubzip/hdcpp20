#include <iostream>

// printv 를 조금 "smart" 하게 만들수 없을까 ??
// => 핵심 : T가 포인터인지 조사할수 있어야 한다.
template<typename T> void printv(const T& value)
{
	if ( T 가 포인터 타입 이면 )
		std::cout << value << " : " << *value << std::endl;
	else 
		std::cout << value << std::endl;
}


int main()
{
	int n = 10;
	printv(n);
	printv(&n);
}