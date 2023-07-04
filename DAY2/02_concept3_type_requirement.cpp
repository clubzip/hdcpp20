#include <iostream>
#include <vector>

// 2. type requirement
template<typename T> 
//concept has_value_type = requires(T a) // T타입의 객체 a를 사용하지 않는다면
concept has_value_type = requires        // 이렇게 해도 됩니다.
{
    typename T::value_type; 
};

class A
{
public:
    using value_type = int;
};

int main()
{
    std::cout << has_value_type<A> << std::endl;
    std::cout << has_value_type< std::vector<int> > << std::endl;
}