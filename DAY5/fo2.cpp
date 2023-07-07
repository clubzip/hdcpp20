// fo1.cpp
#include <iostream>
#include <vector>
#include <algorithm>

bool foo(int n)
{
	return n % 3 == 0;
}
// �Լ��� ���� 1. ���¸� ���� �Լ�!! 
// => �Ʒ� IsMod �� ����� "�Ϲ��Լ�"�� �Ҽ� ������� ??? �ȵ˴ϴ�.

struct IsMod
{
	// �ٽ� : �Լ� ��ü�� Ŭ���� �̹Ƿ� ��� ����Ÿ�� �ֽ��ϴ�.
	//	     ���� ���¸� ������ �Լ� ��� �մϴ�.
	int value;	
	IsMod(int n) : value(n) {}

	bool operator()(int n) const { return n % value; }
};

int main()
{
	std::vector v = { 1,6,3,7,8 };

	int k = 3; 

	IsMod f(k); // f�� ��ü�ε�, 
				// ()������ �Լ��� ������ �����Ƿ� �����Լ�(���ڰ� �Ѱ��� �Լ�)
				// �� ��밡���ϰ�, 
				// ���������� k ���� �����մϴ�.

	bool b = f(10); // return 10 % k == 0

	auto ret3 = std::find_if(v.begin(), v.end(), f );
}