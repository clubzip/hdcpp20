#include <iostream>
#include <type_traits>
#include <vector>


template<typename T> void check(T& c)
{
	// 1. T �� ������ ���� �����ϰ� �ʹ�.
	bool b1 = std::is_pointer<T>::value;  // C++11
	bool b2 = std::is_pointer_v<T>;       // C++17


	// 2. T �� �����̳����� �����ϰ� �ʹ�.

	// => �����̳����� �����ϴ� �ڵ�� ��� ������ �ұ� ?
	//    �� �����ϱ� ����..
	// => "�����̳�" �� "��� ���� �ұ�"��  �߿��մϴ�.

	// concept
	// => Ÿ���� ���� ���Ǹ� �ڵ�� ǥ���ϴ� ����
	// => �׷���, C++ â���ڴ� "is_" �� �������� ����� ����..
	// => name requiresment

}

int main()
{
	int n = 0;
	std::vector<int> v = { 1,2,3 };
	int x[3] = { 1,2,3 };

	check(n);	
	check(v);	
	check(x);   
}