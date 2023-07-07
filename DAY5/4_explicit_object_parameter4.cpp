#include <iostream>
#include <functional>

// deducing this ���� 3. recursive lambda 

int main()
{
    // ���� ǥ������ ��� ȣ��� ����� ������� ?
    // => �Ʒ� �ڵ�� ���� �Դϴ�.
//  auto factorial = [](int n) { return n > 1 ? n * factorial(n - 1) : 1;};

    // �Ʒ� ó�� �ϸ� �˴ϴ�.
    // => ����ǥ���� ������ �ٽ� ���ڷ� �����ϴ� ��
//    auto factorial = [](int n, auto& factorial) { return n > 1 ? n * factorial(n - 1, factorial ) : 1; };
    
//    int n = factorial(5, factorial); // ok.. 
                          // ������ �ڽ��� �ٽ� ���ڷ� �����Ƿ� ���������� �ʽ��ϴ�.

//    std::cout << n << std::endl;

       
    // C++23 �� explicit object parameter �� ����ϸ� �����ϰ� �ذ�˴ϴ�.
    // �ٽ� 1. ����ǥ������ �ᱹ "operator()" ��� �Լ� �Դϴ�.
    //        ��,  [](int n) {} <= �̺κ��� ��� �Լ���� �ǹ�

    auto factorial = [](this auto& self, int n) -> int { return n > 1 ? n * self(n - 1) : 1; };
    
    int n = factorial(5);
            // factorial.operator()(5) �Դϴ�. operator() ��� �Լ� ȣ��!
            // operator()(factorial, 5)
}

// explicit object parameter �� ����ϸ�
// 1. const, non-const member �Լ��� �ϳ��� �Լ�(���ø�)���� ��������
// 2. CRTP ����� ĳ���� ���� ��밡��
// 3. recursive ���� ǥ������ �����ϰ� ����� �ִ�.