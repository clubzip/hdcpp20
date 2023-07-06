#include <iostream>
#include <memory>

int main()
{
	// �ٽ� 1. C++11
	// C++ ǥ�� ����Ʈ ������ ����
	// => ���� new ��������
	// => std::make_shared<> �� ����ϴ� ���� �����ϴ�.

	std::shared_ptr<int> p1(new int);				   // bad
	std::shared_ptr<int> p2 = std::make_shared<int>(); // good

	std::unique_ptr<int> p3(new int);				   // bad
	std::unique_ptr<int> p2 = std::make_unique<int>(); // good


	// 2. ����Ʈ �������� �迭 ���� - C++14, C++17
	std::unique_ptr<int> up1(new int);		// ok. up1 �Ҹ��ڰ� delete
//	std::unique_ptr<int> up2(new int[10]);  // ����, new[] �ε�..
											// �Ҹ��ڴ� delete ����

	std::unique_ptr<int[]> up2(new int[10]);// ok. �Ҹ��ڰ� delete[] ����
											// C++14


	std::shared_ptr<int>   sp1(new int);	// ok, �Ҹ��ڰ� delete
	std::shared_ptr<int[]> sp2(new int[10]);// ok. �Ҹ��ڰ� delete[]
											// C++17

	// �迭 ������ ����Ʈ �����ʹ� make_shared �ȵǳ��� ?
	// => C++20 ���� ���ԵǾ����ϴ�.
	std::shared_ptr<int[]> sp3 = std::make_shared<int[10]>(); // 10�� �Ҵ� 
	std::shared_ptr<int[]> sp4 = std::make_shared<int[]>(10); // 10�� �Ҵ�

	std::shared_ptr<int[]> sp3 = std::make_shared<int[10]>(1);  // 10���� 1���ʱ�ȭ
	std::shared_ptr<int[]> sp4 = std::make_shared<int[]>(10,1); // 10���� 1���ʱ�ȭ
}
