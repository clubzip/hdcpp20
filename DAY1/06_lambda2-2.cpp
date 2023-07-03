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
	// �����ڷ� �Լ� ��ü ���� - ok!!
	std::unique_ptr<int, Freer> p1((int*)malloc(sizeof(int)));


//	std::unique_ptr<int, [](int* p) { free(p); } > p2((int*)malloc(sizeof(int)));
					// error 
					// ����ǥ������ ����� ��ü����, Ÿ���� �ƴմϴ�.

//	std::unique_ptr<int, decltype( [](int* p) { free(p); } )  > p2((int*)malloc(sizeof(int)));
					// C++20 �������� ����
					// => ���� ǥ������ �� ���� ���� ǥ���Ŀ� 
					//	  ������ ����.

	auto del = [](int* p) { free(p); };

//	std::unique_ptr<int, decltype(del) > p2((int*)malloc(sizeof(int)));
			// => ���ø� ���ڷ� ������ ����.
			// => ������ ����ǥ������ ���� Ÿ���� ����Ʈ �����ڰ� ���
			//	  error ( C++20 ����)

	// �ᱹ C++20 �������� �Ʒ� ó�� �ؾ� �մϴ�. 
	// => effective modern C++ �� �ִ� ����.
	// 
	// 1. ���� ǥ������ ���� auto ������ ��������
	auto del2 = [](int* p) { free(p); }; 

	// 2. Ÿ���� �����ϰ�, �����ڷ� del2 �� �����ϼ���
	std::unique_ptr<int, decltype(del2)> 
					p2((int*)malloc(sizeof(int)), del2);

	// ������ C++20 ���ʹ�
	// => ����ǥ������ �򰡵��� �ʴ� ǥ���Ŀ� ������ �ְ�
	// => ����Ʈ �����ڵ� �����Ƿ�
	// �Ʒ� ó�� �ϸ� �˴ϴ�.
	std::unique_ptr<int, decltype([](int* p) { free(p); })>
									p2((int*)malloc(sizeof(int)));
}




template<typename T, typename D = std::default_delete<T>>
class unique_ptr
{
	D del;
	T* obj = nullptr;
public:
	unique_ptr(T* p, const D& d) : obj(p), del(d) {}

	~unique_ptr()
	{
		del(obj);
	}
};
