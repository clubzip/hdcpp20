#include <iostream>
#include <span>

int main()
{
    // �ٽ� 1. �Ʒ� ó�� �ʱ�ȭ�� �ȵ˴ϴ�.
//  std::span<int> sp = { 1,2,3 }; // error


    // �ٽ� 2. �迭�� ������
    int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
    
    int* p = new int[10] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; // C++11 ���� ����


    // �迭 �̸� x : �迭�� ����ϴ� �޸� �ּ� + �迭�� ũ�� ������ ����
    //              sizeof(x) => 40 ����Ʈ
    // 
    // �������̸� p : �޸� �ּ� ������ ����. 
    //              sizeof(p) => 4(32bit), 8(64bit)


    // �ٽ� 3. �迭�� span �� �ʱ�ȭ �Ҷ�
    std::span<int>     sp1(x);  // x �� �迭�� �̸��̹Ƿ� �̷��Ը� �ص� sp1�� 
                                // ũ�� ������ ������ �˴ϴ�.
                                // => ũ�� ������ ������ ��� ����Ÿ�� ����
                                // => ���� sp1 �� ��� = ������ũ�� + size_tũ��
    
    std::span<int, 10> sp2(x);  // ���ø� ���ڷ� ũ�⸦ �����ϸ� 
                                // ũ�������� �ٷ� �ڵ忡 ����( �ڵ�ȿ� "10" ����)
                                // => ũ�� ���� ������ �ʿ� ����.

    std::span<int>     sp3(x, 10);
    std::span<int, 10> sp4(x, 10);

    std::cout << sizeof(sp1) << std::endl; // ������ ũ�� + size ���� ũ��
    std::cout << sizeof(sp2) << std::endl; // ������ ũ�� 
    std::cout << sizeof(sp3) << std::endl;
    std::cout << sizeof(sp4) << std::endl;

    // �ٽ� 4. �����ͷ� �ʱ�ȭ �Ҷ�
    // => ������ �̸����� ũ�� ������ �����ϴ�.
    // => ������ ���ڷ� �ݵ�� ũ�� ������ ������ �մϴ�.
//  std::span<int>     sp5(p);  // error
//  std::span<int, 10> sp6(p);  // error
    std::span<int>     sp7(p, 10); // ok
    std::span<int, 10> sp8(p, 10); // ok


    // �ٽ� 5. �پ��� ��� �Լ� ��
    std::span<int>     sp11(x);  
    std::span<int, 10> sp12(x);  

    std::cout << sp11.extent << std::endl;
    std::cout << sp12.extent << std::endl;

    std::cout << sp11.size() << std::endl;
    std::cout << sp11.size_bytes() << std::endl;
    std::cout << sp12.size() << std::endl;
    std::cout << sp12.size_bytes() << std::endl;

//   int* p = x;
//  std::span<int> sp3(p);     
//  std::span<int> sp4(p, 10); 
}