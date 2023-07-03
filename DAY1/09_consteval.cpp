// C++11. constexpr function
// 1. 실행시간에 실행될수도 있고
// 2. 인자를 컴파일 시간에 알고, 컴파일시간에 결과가 필요하면 컴파일 시간에 수행
constexpr int square1(int n)
{
    return n * n;
}
// consteval function : 컴파일 시간에만 동작하는 함수.
//                      인자값은 반드시 컴파일시간에 알수 있는 값만 가능
consteval int square2(int n)
{
    return n * n;
}
int main()
{
    int x = 10;

              int ret1 = square1(x); // ok. 실행시간
    constexpr int ret2 = square1(3); // ok. 컴파일 시간

              int ret3 = square2(x); // error. 
    constexpr int ret4 = square2(3); // ok. 컴파일 시간

}
