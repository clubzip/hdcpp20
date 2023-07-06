#include <iostream>

// variable template ���� - C++14 ����

constexpr int variable = 0;		// �Ϲ� ��������(���)

template<typename T>
constexpr int made_year = 0;	// ���ø����� ���� ��������
								// "variable template"
class Date
{
};
// ����, variable template �� made_year �� "Date" Ÿ�Կ� ���ؼ� Ư��ȭ �մϴ�.
template<>
constexpr int made_year<Date> = 2023;

int main()
{
	std::cout << variable  << std::endl; // ok
//	std::cout << made_year << std::endl; // error. template �ε�, ���ڰ� �����Ƿ�

	std::cout << made_year<int>   << std::endl; // ok. 0
	std::cout << made_year<float> << std::endl; // ok. 0
	std::cout << made_year<Date> << std::endl;  // 2023
}



