// C++11. constexpr function
// 1. ����ð��� ����ɼ��� �ְ�
// 2. ���ڸ� ������ �ð��� �˰�, �����Ͻð��� ����� �ʿ��ϸ� ������ �ð��� ����
constexpr int square1(int n)
{
    return n * n;
}
// consteval function : ������ �ð����� �����ϴ� �Լ�.
//                      ���ڰ��� �ݵ�� �����Ͻð��� �˼� �ִ� ���� ����
consteval int square2(int n)
{
    return n * n;
}
int main()
{
    int x = 10;

              int ret1 = square1(x); // ok. ����ð�
    constexpr int ret2 = square1(3); // ok. ������ �ð�

              int ret3 = square2(x); // error. 
    constexpr int ret4 = square2(3); // ok. ������ �ð�

}
