#include <iostream>
#include <vector>

// 2. type requirement
template<typename T> 
//concept has_value_type = requires(T a) // TŸ���� ��ü a�� ������� �ʴ´ٸ�
concept has_value_type = requires        // �̷��� �ص� �˴ϴ�.
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