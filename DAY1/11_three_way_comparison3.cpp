#include <compare>
#include <cstring>

// 문자열을 비교하는 경우를 생각해 봅시다.
// 1. operator<=> 의 디폴트 버전을 사용하면 "buff의 값(메모리주소)"로 비교
//    => 잘못된 동작

class String
{
    char* buff;
    int   size;
public:
    String(const char* s)
    {
        size = strlen(s);
        buff = new char[size + 1];
        strcpy(buff, s);
    }
    ~String() { delete[] buff; }


    auto operator<=>(const String& s) const
    {
//      return strcmp(buff, s.buff); // 이렇게 하면 반환 타입이 int 입니다.
        return strcmp(buff, s.buff) <=> 0; // 이렇게 하면 <=> 의 결과
                                            // std::strong_odering
    }

    // <=> 만 만들면 되지 않나요 ?? 
    // 왜 == 를 따로 만들라고 하나요 ?
    // => 많은 경우, == 는 <=> 와 다른 방식으로 최적화 가능합니다.
    bool operator==(const String& s) const
    {
        // 문자열 길이가 같은 경우만 <=> 사용해서 비교!!
        return size == s.size && (*this <=> s) == 0;
    }
};





int main()
{
    String s1("ABCD");
    String s2("ABCXYZ");

    bool ret = s1 == s2; 

}
