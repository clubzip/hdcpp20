#include <iostream>


int main()
{
    int a = 10, b = 20;

    // ���� C++ : 6���� �� �����ڰ� �ֽ��ϴ�.
    //            ==, !=, <, <=, >, >=
    bool ret1 = a < b;

    
    // C++20 �� ���ο� �� ������
    // ���� ��Ī : three way comparision operator
    // ����      : spaceship operator(���ּ� ������)
    auto ret2 =   a <=> b;


    // ��ȯ���� 0 ���� ū��, �������� �� �մϴ�.
    if (ret2 > 0) // ret2 >= 0
        std::cout << "a > b" << std::endl;

    else if ( ret2 == 0 )
        std::cout << "a == b" << std::endl;

    else if (ret2 < 0)  // ret2 <= 0
        std::cout << "a < b" << std::endl;

    // ���� ret2�� Ÿ���� int �ƴմϴ�.
    std::cout << typeid(ret2).name() << std::endl;
                        // => std::strong_ordering ��� Ÿ��


}
