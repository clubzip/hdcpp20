// ����, C/C++ ���� ���̺귯���� ����� ���
// .c(.cpp) : �Լ�(Ŭ����)�� ������ �ۼ�
// .h       : �Լ�(Ŭ����)�� ����� �ۼ�

// => ���̺귯�� ����ڴ� #include "�������" �� ���
// ���� 1. ������ �ð��� ���� �ɸ���.
// ���� 2. ����� ����� include �ϴ� ���� �߻�
//        "include guard", "#pragma once" ��� ���

// ��κ��� �ٸ� ���� ��������� ������ �����ϴ�.


// �ٽ� : C++20 ��� ���� ����
// => ���̺귯�� ����� �� �̻� ����� ���� �ʿ� �����ϴ�.
// => ������ �ӵ��� �������ϴ�.
// => �׷���, ���� ���� C++ �����Ϸ��� "�κ������θ� ����" �մϴ�.


// �ٽ� 1. ���(���̺귯��)�� Ȯ���ڴ� ǥ�ؿ��� ������� �ʽ��ϴ�.
// => �����Ϸ����� �ٸ��� �ֽ��ϴ�
// => Visual Studio �� .ixx �Դϴ�.


// mymath.ixx
// ���� ��� : cl  math.ixx /c  /std:c++20
// �����		: mymath.obj    mymath.ifc

#include <iostream>

export module mymath;

// export �� ���� ���. 
// ��� ���ο����� ��밡���մϴ�
export int add(int a, int b)
{
	return a + b;
}
export class Point
{
	int x, y;
public:
	Point(int x, int y) :x(x), y(y) {}

	void print() const { std::cout << x << ", " << y << std::endl; }
};

