#include <iostream>
#include <vector>
#include <array>

// C++20 std::to_array
int main()
{
//	int x[10]{ 1,2,3,4,5,6,7,8,9,10 };
//	std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	std::array<int, 10>  a{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 

	// C++17 ���ʹ� ���ø� ���� ���������ϹǷ�, ����ϱ� ���� �����ϴ�.
	int x[10]{ 1,2,3,4,5,6,7,8,9,10 };
	std::vector v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::array  a{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };


	// �迭         : ��� ��Ұ� stack �� ���Դϴ�.
	// std::vector : ��� ��Ұ� heap  �� ���Դϴ�. 
	// std::array  : ��� ��Ұ� stack �� ���Դϴ�. 
	//			     ���� �迭�� �޸� ������ �Ϻ��� ����
	//				 a.size() ���� �Լ��� �����Ǿ ���� �迭���ٴ� ��
	
	// C++20 ���� std::array �� ���� ����� std::to_array() ����.
	auto a1 = std::to_array("foo");		// std::array<char, 4>
	auto a2 = std::to_array( {1,2,3});	// std::array<int, 3>
	auto a3 = std::to_array( x);		// raw array => std::array
}
