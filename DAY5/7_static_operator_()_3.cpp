#include <iostream>

class less
{
public:
	bool operator()(int a, int b)
	{
		return a < b;
	}

	using F = bool(*)(int, int);


	static bool helper(int a, int b)
	{
		return a < b;
	}
	operator F() { return &less::helper; }
};

int main()
{
	// ����ǥ������ �Լ� �����ͷ� �Ͻ��� ��ȯ �ɼ� �ֽ��ϴ�.
	bool(*f)(int, int) = [](int a, int b) { return a < b; };

}