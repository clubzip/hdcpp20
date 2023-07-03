#include <iostream>
#include <type_traits>

// C++ 표준 스마트 포인터 unique_ptr 을 생각해 봅시다.
// => 내부적으로 메모리 주소와 삭제자를 보관해야 합니다.

template<typename T, typename D> 
class unique_ptr
{
	T* addr;
	D  del;   // 삭제자
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

// lambda 2 에서 Freer 복사해 오세요.
