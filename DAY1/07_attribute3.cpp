#include <iostream>

// [[no_unique_address]]

// �ٽ� 1. empty class �˾� �μ���.
// empty class : non-static �������Ÿ�� �����Լ��� ���� Ŭ����
//               sizeof(empty) == 1 �Դϴ�.(�������� ���)
struct Empty
{
    void foo() {} // �Ϲ� ��� �Լ��� �־ empty �Դϴ�.
};
Empty e;    // �ƹ� ����� ������, ũ��� 1�Դϴ�.

// �ٽ� 2. empty class �� ��� ����Ÿ�� ���̸� ũ�� ��꿡 ���Ե˴ϴ�.
struct Data1
{
    Empty e;
    int   n;
};

// �ٽ� 3. empty class �� ���� ��� ������ empty �� ũ��� ��� ���� �ʽ��ϴ�.
// => EBCO : Empty Base Class Optimization �̶�� �մϴ�.
struct Data2 : public Empty
{
    int   n;
};

// �ٽ� 4. C++20 [[no_unique_address]] attribute �� ����ϸ�
//        Empty �� ����� �־ ũ�⿡ ���Ե��� �ʽ��ϴ�.
struct Data3
{
    [[no_unique_address]] Empty e;
    int   n;
};

int main()
{
    std::cout << sizeof(Empty) << std::endl; // 1
    std::cout << sizeof(Data1) << std::endl; // 8
    std::cout << sizeof(Data2) << std::endl; // 4
    std::cout << sizeof(Data3) << std::endl; // 4
}
// g++ 13.x : ����
// visual studio 2022 : �����ȵ�.
//                      [[no_unique_address]] �� ������ �ƴ�