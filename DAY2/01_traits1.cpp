#include <iostream>

// printv �� ���� "smart" �ϰ� ����� ������ ??
// => �ٽ� : T�� ���������� �����Ҽ� �־�� �Ѵ�.
template<typename T> void printv(const T& value)
{
	if ( T �� ������ Ÿ�� �̸� )
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