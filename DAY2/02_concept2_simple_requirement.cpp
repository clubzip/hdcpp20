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
template<typename T> concept C1 = f1();
template<typename T> concept C2 = f2();
template<typename T> concept C3 = f3();
template<typename T> concept C4 = f4();






int main()
{

}