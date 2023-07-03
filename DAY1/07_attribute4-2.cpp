#include <iostream>
#include <type_traits>

template<typename T1, typename T2, bool b = std::is_empty_v<T1>>
struct PAIR
{
	T1 first;
	T2 second;
};
// 3��° ���ڰ� true �� ��츦 ���� �κ� Ư��ȭ
// ��, PAIR �� 1��° ���ڰ� empty �� ��츦 ���� �κ� Ư��ȭ �Դϴ�.
template<typename T1, typename T2>
struct PAIR<T1, T2, true> : public T1
{
	T2 second;
};

/*
// C++20 ���ʹ� PAIR �� ��ó�� �����ʿ� ����
// [[no_unique_address]] �� ����ϸ� �˴ϴ�.
template<typename T1, typename T2>
struct PAIR
{
	[[no_unique_address]] T1 first;
	[[no_unique_address]] T2 second;
};
*/



// C++���� �������� empty �� �����ϴ�
// => ��κ��� �Լ� ��ü
// => ���� ǥ������ ����� ��ü
// => STL �� allocator 
// ���� ��� empty class �Դϴ�.

struct Freer
{
	void operator()(void* p) noexcept
	{
		free(p);
	}
};


// C++ ǥ�� ����Ʈ ������ unique_ptr �� ������ ���ô�.
// => ���������� �޸� �ּҿ� �����ڸ� �����ؾ� �մϴ�.

template<typename T, typename D> 
class unique_ptr
{
//	T* addr;
//	D  del;   // ������

	// STL ���ο� �Ʒ��� ���� ������ "compressed pair" ��� Ŭ������
	// �θ� ���˴ϴ�.
	// empty �� �����Ҷ� �޸� ����� �ּ�ȭ �ϴ� ����Դϴ�.
	PAIR<D, T*> pa;

public:
	unique_ptr(T* p) { pa.second = p; }

	~unique_ptr()
	{
		// �ּҴ� pa.second �� ���� �ǰ�,
		// �����ڴ� �ᱹ pa�� ��� Ŭ�����̹Ƿ� operator()��
		// ���� �ް� �˴ϴ�.
		//del(addr);
		pa.operator()(pa.second);
	}
};

int main()
{
	unique_ptr<int, Freer> up(new int);

	std::cout << sizeof(up) << std::endl;
}

// lambda 2 ���� Freer ������ ������.
