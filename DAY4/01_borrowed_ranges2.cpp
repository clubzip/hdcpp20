#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <ranges>

int main()
{
    std::string s = "hello";

    auto p1 = std::ranges::begin( std::vector{1,2,3} ); 
                        // => �ڿ��� �����ϴ� �����̳ʰ� �ӽð�ü�� �����ϴ� ���
                        // => ������ ����

    auto p2 = std::ranges::begin(std::string_view{ s });
                        // => string_view ��ü�� �ڿ��� �������� �ʽ��ϴ�
                        // => string_view �� �ı� �Ǿ.. �ڿ��� ���������Ƿ�
                        // => ��ȯ�� �ݺ��ڴ� ��ȿ�� �ݺ��� �Դϴ�.

    // �ٽ� : � "range" �� �ڿ��� ���������� ? �ڿ��� ������ ����ϴ���?
    //       �� �߿��մϴ�.

    // range : begin, end �� ���� ��(�����̳�, view)
}
