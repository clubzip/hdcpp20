
// likely
// Pipeline
// => CPU 는 하나의 명령을 실행할때 
// => 다음 실행할 명령을 가지고 와서 캐쉬에 보관합니다.

int foo(int i)
{
    int i = 0;
    i = 1;
    i = 2;

    if (i > 0)  [[likely]] // if 문이 true일 확률이 높다고 알려주는것
        i += 2;
    else
        i -= 2;

    // 리눅스 커널에서 널리 사용합니다.
    // => 리눅스 커널은 C++이 아니므로
    // => gcc 확장 명령으로 합니다.
//  if (likely(i > 0))
//  {
//   }

    return i;
}



int main()
{
    foo(10);
    return 0;
}
