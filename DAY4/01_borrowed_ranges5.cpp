#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <algorithm>

int main()
{
    // std::ranges::begin �� rvalue range(�ӽð�ü) �� �����ϴ� ���

//  auto p = std::ranges::begin(std::vector{1, 2, 3});
                // => ���ڰ� borrowed range ��� ok
                // => ���ڰ� borrowed range �� �ƴϸ� error


    // std::ranges::begin �� �ƴ�
    // std::ranges �˰��� rvalue range �� �����ϴ� ���

    // 1. �ݺ��ڰ� �ƴ� ���� ��ȯ�ϴ� ���. �ƹ� ���� ����.
    auto n = std::ranges::min(std::vector{5, 4, 3, 1, 2, 9});
    std::cout << n << std::endl; // 


    // 2. �ݺ��ڸ� ��ȯ�ϴ� �˰���, borrowed_range �� �ƴ� ���� �ӽð�ü����
    // => std::ranges::dagling �̶�� Ÿ������ ��ȯ��..
    // => std::ranges::dagling Ÿ���� * ���� ���� ����, * ���� ����
    // => C�� dangling pointer ������ Ÿ��ȭ �Ѱ�
    auto p1 = std::ranges::find(std::vector{1, 2, 3}, 2);
//  *p1 = 10;


    // 3. �ݺ��ڸ� ��ȯ�ϴ� �˰���, borrowed_range �� �ӽð�ü����
    std::string s{ "Hello" };
    auto p2 = std::ranges::find(std::string_view{s}, 'e');

    auto c = *p2; // ok.. 

}