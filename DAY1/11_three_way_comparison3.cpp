#include <compare>
#include <cstring>

// ���ڿ��� ���ϴ� ��츦 ������ ���ô�.
// 1. operator<=> �� ����Ʈ ������ ����ϸ� "buff�� ��(�޸��ּ�)"�� ��
//    => �߸��� ����

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
//      return strcmp(buff, s.buff); // �̷��� �ϸ� ��ȯ Ÿ���� int �Դϴ�.
        return strcmp(buff, s.buff) <=> 0; // �̷��� �ϸ� <=> �� ���
                                            // std::strong_odering
    }

    // <=> �� ����� ���� �ʳ��� ?? 
    // �� == �� ���� ������ �ϳ��� ?
    // => ���� ���, == �� <=> �� �ٸ� ������� ����ȭ �����մϴ�.
    bool operator==(const String& s) const
    {
        // ���ڿ� ���̰� ���� ��츸 <=> ����ؼ� ��!!
        return size == s.size && (*this <=> s) == 0;
    }
};





int main()
{
    String s1("ABCD");
    String s2("ABCXYZ");

    bool ret = s1 == s2; 

}
