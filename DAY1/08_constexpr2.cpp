class Base
{
public:
	virtual int foo(int a, int b) { return a + b; }
};

class Derived : public Base
{
public:
	// C++20 ���� �����Լ����� constexpr ��밡���մϴ�.
	// constexpr : ������ �ð��� ����� �ʿ� �ִٸ� ������ �ð��� ������ �޶�.
	constexpr int foo(int a, int b) override { return a + b; }
};

int main()
{
	// �����Լ� ȣ��� ��Ȯ�� ��ü �̸����� ȣ���ϸ�
	// "������ �ÿ� ����ɼ� �ֽ��ϴ�."
	Derived d;					// d�� Ÿ���� �����Ϸ��� �˰� �˴ϴ�.
	int ret1 = d.foo(1, 2);		// ����ð� ȣ��
	constexpr int ret2 = d.foo(1, 2);	// ����� constexpr �� �����Ƿ� 
										// d.foo()�� ������ �ð��̾�� �մϴ�.
										// C++20 ���ʹ� ok.


	Base* p = &d;				// ��� Ŭ���� �����ͷ� �����Լ� ȣ���
	int ret3 = p->foo(1, 2);	// ok
//	constexpr int ret4 = p->foo(1, 2);	// error.
										// �����Լ� �̹Ƿ� �����Լ� ���̺� ����ؼ�
}										// ȣ��
