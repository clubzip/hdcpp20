#include <iostream>



int main()
{
	// ����ǥ������ �Լ� �����ͷ� �Ͻ��� ��ȯ �ɼ� �ֽ��ϴ�.	
//	bool(*f)(int, int) = [](int a, int b) { return a < b; };

	// �� ������ ����

	// 1. �����Ϸ��� �� ���� ǥ������ ���� �Ʒ� �ڵ带 �����մϴ�
	class CompilerGeneratedName
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
		operator F() { return &CompilerGeneratedName::helper; }
	};


	// 2. �� ������ �Ʒ� �ڵ� �Դϴ�.
	bool(*f)(int, int) = CompilerGeneratedName();
}