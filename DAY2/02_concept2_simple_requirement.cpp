#include <iostream>
#include <type_traits>
#include <string>
#include <vector>
#include <algorithm>

// Concept �� ����� ��� 1. Simple requirement

// 1. concept �� ����� �⺻ ���
// template<typename T>
// concept ���ϴ��̸� = �����Ͻð���_�����ɼ��ִ�_bool_��;


// ex1. bool literal ���
template<typename T>
concept always_true = true;

bool b1 = always_true<int>; // ��� Ÿ���� �־ true �Դϴ�.


// ex2. �����Ͻð��� ȣ�Ⱑ���� �Լ�
          bool f1() { return true; }
const     bool f2() { return true; }
constexpr bool f3() { return true; }
consteval bool f4() { return true; }

//                                �̺κ��� �����Ͻð��� bool ������ ���������ϸ� ok
template<typename T> concept C1 = f1(); // error ( ����ϸ� ���� �Դϴ�. C1<int>)
template<typename T> concept C2 = f2(); // error
template<typename T> concept C3 = f3(); // ok
template<typename T> concept C4 = f4(); // ok

//bool b2 = C1<int>; // error
bool b3 = C3<int>; // ok



// ex3. type_traits�� ���� �˴ϴ�.- ���� ���� ����մϴ�.
// => ��?? traits �� ����ϸ� �Ǵµ�, �ٽ� concept �� ���峪�� ?
// => traits �� ���ϴ� �۾��� concept ���� ������ ���� �ֽ��ϴ�.
//    (require caluse, syntax sugar ���� ����)
template<typename T>
concept pointer = std::is_pointer_v<T>;

// ���� ������ ���� �����ϴ� 2���� ���
bool b4 = std::is_pointer_v<int>; // traits �� ���� ���
bool b5 = pointer<int>;           // ������ ���� concept ���


// ex4. && || ��밡���մϴ�
template<typename T>
concept signed_integer = std::is_integral_v<T> && std::is_signed_v<T>;

bool b6 = signed_integer<int>;


int main()
{

}