#include <iostream>
#include <memory>

struct Freer
{
	void operator()(void* p) noexcept
	{
		free(p);
	}
};

int main()
{
	
	std::unique_ptr<int> p1(new int);	// new �� �Ҵ��� ���,
										// p1�� �Ҹ��ڰ� delete �� ����.
										// 
	// unique_ptr �� ������ ������ ���ø� 2��° ���ڷ� �Լ� ��ü�� �����մϴ�.
	std::unique_ptr<int, Freer> p2(static_cast<int*>(malloc(sizeof(int))));


	// �ᱹ ���� ǥ������ �Լ� ��ü�� ����� ǥ��� �Դϴ�
	// �׷��ٸ� �Ʒ� ó�� ����Ҽ� ������� ?
//	std::unique_ptr<int, [](int* p) { free(p); } >  p3(static_cast<int*>(malloc(sizeof(int))));
			// => error. 
			// => ���� ǥ������ ���� ����� "�ӽð�ü" ���� Ÿ���� �ƴմϴ�.
			// => ���ø� ���ڴ� ��ü�� �ƴ� Ÿ���� �����ؾ� �մϴ�.

	std::unique_ptr<int, decltype([](int* p) { free(p); }) > p3(static_cast<int*>(malloc(sizeof(int))));
				// C++20 ���� �˴ϴ�.
				// C++17 �������� �Ʒ� ó�� �ؾ� �մϴ�.

}






template<typename T, typename D = std::default_delete<T>> class unique_ptr
{
	T* obj = nullptr;
public:
	~unique_ptr()
	{
	}
};
