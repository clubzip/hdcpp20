#include <iostream>
#include <type_traits>	// C++11 에서 추가된 헤더
						// 이 헤더 안에 아래 만든 is_pointer 가 있습니다
// T 가 포인터 인지 조사하는 방법 

// 1. 구조체 템플릿을 만들고 false 반환 ( value = false 로 하라는 의미)
template<typename T> struct is_pointer
{
//	enum { value = false }; // 예전 스타일
	static constexpr bool value = false; // C++11 이후 스타일
};
// 2. 조건을 만족하도록 부분 특수화 버전을 만들고,  true 반환(value = true)
template<typename T> struct is_pointer<T*>
{
//	enum { value = true };
	static constexpr bool value = true; 
};

template<typename T> 
void foo(const T& value)
{
	// T : int, int*
	//if   ( is_pointer<T>::value  )
	if (std::is_pointer<T>::value)
		std::cout << "pointer" << std::endl;
	else 
		std::cout << "not pointer" << std::endl;
}


int main()
{
	int n = 10;
	foo(n);
	foo(&n);
}