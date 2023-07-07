// fo1.cpp
#include <iostream>
#include <vector>
#include <algorithm>

bool foo(int n)
{
	return n % 3 == 0;
}

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

	IsMod f(k); // f�� �����Լ�(���ڰ� �Ѱ��� �Լ�) �ε�..
				// ���������� k ���� �����մϴ�.

	auto ret3 = std::find_if(v.begin(), v.end(), f );
}