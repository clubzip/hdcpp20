#include <iostream>
#include <concepts>

template<typename T> 
concept C2 = requires(T x)
{
    // T Ÿ���� ��ü���� + 1 �� �����ؾ� �Ѵ�.
    x + 1;      

    // ����(�Լ�ȣ��)�� ����� ���ǿ� ���Խ�Ű�� ���
//  { x + 1 } -> int;   // error. Ÿ���� ���� ������ �ȵǰ�!!
                        // concept ���� ǥ���ؾ� �մϴ�.
    { x + 1 } -> std::same_as<int>; // ok. ����� int �̾�� �Ѵ�.
                        // => �ٽ�, same_as �� Ÿ�����ڴ� ���� 2���ε�..
                        //    �� ��ġ�� ǥ���Ҷ��� ���ڰ� 1���� 
                        // std::same_as<x+1�ǰ��Ÿ��, int>

    // C++ ���������� "same_as" ���ٴ� "convertible_to" �� ���� �մϴ�
    // => "int �̾�� �Ѵ�" �� �ƴ϶�
    // => "int�� ��ȯ �����ؾ� �Ѵ�" �� �ǹ�.
    // =>  std::convertible_to<x+1�ǰ��Ÿ��, int>
    {x + 1} -> std::convertible_to<int>;
};



int main()
{

    // 2���� Ÿ���� ������ �����ϴ� ���
    // 1. traits ���
    bool b1 = std::is_same_v<int, int>;    // true
    bool b2 = std::is_same_v<int, double>; // false

    // 2. concept ��� => C++ ǥ���� �����ϴ� �̸� ������� concept �� �ֽ��ϴ�.
    bool b3 = std::same_as<int, int>; // true
                            // ���� ���� ������ std::is_same_v ���
}