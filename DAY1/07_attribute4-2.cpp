#include <iostream>
#include <type_traits>

template<typename T1, typename T2, bool b = std::is_empty_v<T1>>
struct PAIR
{
	T1 first;
	T2 second;
};
// 3번째 인자가 true 인 경우를 위한 부분 특수화
// 즉, PAIR 의 1번째 인자가 empty 인 경우를 위한 부분 특수화 입니다.
template<typename T1, typename T2>
struct PAIR<T1, T2, true> : public T1
{
	T2 second;
};

/*
// C++20 부터는 PAIR 를 위처럼 만들필요 없이
// [[no_unique_address]] 를 사용하면 됩니다.
template<typename T1, typename T2>
struct PAIR
{
	[[no_unique_address]] T1 first;
	[[no_unique_address]] T2 second;
};
*/



// C++에는 생각보다 empty 가 많습니다
// => 대부분의 함수 객체
// => 람다 표현식이 만드는 객체
// => STL 의 allocator 
// 등이 모두 empty class 입니다.

struct Freer
{
	void operator()(void* p) noexcept
	{
		free(p);
	}
};


// C++ 표준 스마트 포인터 unique_ptr 을 생각해 봅시다.
// => 내부적으로 메모리 주소와 삭제자를 보관해야 합니다.

template<typename T, typename D> 
class unique_ptr
{
//	T* addr;
//	D  del;   // 삭제자

	// STL 내부에 아래와 같은 개념의 "compressed pair" 라는 클래스가
	// 널리 사용됩니다.
	// empty 를 보관할때 메모리 사용을 최소화 하는 기술입니다.
	PAIR<D, T*> pa;

public:
	unique_ptr(T* p) { pa.second = p; }

	~unique_ptr()
	{
		// 주소는 pa.second 에 보관 되고,
		// 삭제자는 결국 pa의 기반 클래스이므로 operator()를
		// 물려 받게 됩니다.
		//del(addr);
		pa.operator()(pa.second);
	}
};

int main()
{
	unique_ptr<int, Freer> up(new int);

	std::cout << sizeof(up) << std::endl;
}

// lambda 2 에서 Freer 복사해 오세요.
