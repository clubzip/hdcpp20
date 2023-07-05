#include <iostream>
#include <vector>
#include <span>

// string_view(C++17) : ����(char)Ÿ�Կ� ���� ���ӵ� �޸𸮸� ����Ű�� view
// span(C++20)        : ����Ÿ�Կ�       ���� ���ӵ� �޸𸮸� ����Ű�� view
//                      string_view �� generic ����
//void foo(int* arr)  // �ּҸ� �ް� �˴ϴ�.
void foo(std::span<int> sp) // �ּ� �� ���̸� ��� �ް� �˴ϴ�.
{
    std::cout << sp.size() << std::endl;  // 10
}

int main()
{
    std::vector<int> v1 = { 1,2,3,4,5 };

    // �ٽ� 1. span �� string_view �� generic ����
    std::vector<int> v2 = v1; // ���۸� ���� �ϰ� �˴ϴ�.
    std::span<int>   sp = v1; // v1 ���ۿ� ���� view �Դϴ�.
    
    // �ٽ� 2. span �� ���ӵ� �޸𸮴� ��� �͵� ����ų�� �ֽ��ϴ�.
    int arr[3] = { 1,2,3 };
    std::span<int> sp2 = arr;  // sp2 �� "arr�ּ� + ũ��"

    // �ٽ� 3. span �� ���� �����մϴ�.
    // => ���� : string_view �� �б⸸ ����..!
    sp2[0] = 20;
    std::cout << arr[0]     << std::endl; // 20
    std::cout << sp2.size() << std::endl; // 3


    // �ٽ� 4. �迭�� �Լ��� �����Ҷ�
    // => int* �� ������, �ּҿ� ���̸� ���� �޾ƾ� �մϴ�.
    // => std::span ���� �޴� ���� ���մϴ�.

    int x[10]{1,2,3,4,5,6,7,8,9,10};
    // std::vector<int> x{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    foo(x);
}