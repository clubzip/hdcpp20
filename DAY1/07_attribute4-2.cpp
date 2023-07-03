#include <iostream>
#include <type_traits>

// C++ ǥ�� ����Ʈ ������ unique_ptr �� ������ ���ô�.
// => ���������� �޸� �ּҿ� �����ڸ� �����ؾ� �մϴ�.

template<typename T, typename D> 
class unique_ptr
{
	T* addr;
	D  del;   // ������
public:
	unique_ptr(T* p) : addr(p) {}

	~unique_ptr()
	{
		del(p);
	}
};

int main()
{
	unique_ptr<int, Freer> up(new int);

	std::cout << sizeof(up) << std::endl;
}

// lambda 2 ���� Freer ������ ������.
