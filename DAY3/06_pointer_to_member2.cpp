#include <iostream>
#include <functional> // C++17 �� std::invoke ���..
class Dialog
{
public:
	void close1(int a) {}
	static void close2(int a) {}
};
void foo(int a) {}

// �ٽ� : ��� �Լ��� �Լ� ������
// 1. �Ϲ� �Լ� �����Ϳ� ��� �Լ��� �ּҸ� ������ ����. - this ������ 
// 2. �Ϲ� �Լ� �����Ϳ� static ��� �Լ��� �ּҴ� ������ �ִ�.
int main()
{
	void(*f1)(int) = &foo;				// ok
//	void(*f2)(int) = &Dialog::close1;	// error. close1�� this�� �߰��Ǵ� �Լ�
	void(*f3)(int) = &Dialog::close2;	// ok


	// �ٽ� 3. ��� �Լ� �ּҸ� ��� �����͸� ����� ��� 
	void(Dialog::*f2)(int) = &Dialog::close1;

	// �ٽ� 4. ��� �Լ� �����ͷ� �Լ� ȣ���ϴ� ���
//	f2(10); // ��� �Լ��� ȣ���Ϸ��� ��ü(this)�� �ʿ��ѵ�..
			// �� �ڵ�� ��ü�� ����.

	Dialog dlg;
//	dlg.f2(10); // error. 
				// dlg �ȿ��� f2��� �̸��� ã�µ�, f2��� ����� ����.

	// �̶� ����ϴ� �����ڰ� "pointer to member" ��� .* ->* ������
	// .* : �Ѱ��� ������, C���� ���� C++ ����
//	dlg.*f2(10);// error. ������ �켱������ .* ���� ( ������.

	(dlg.*f2)(10);	// ok!! () �� ����ؼ� �켱���� ���ΰ�!!
					// �� ǥ����� ��� �Լ� �����ͷ� �Լ� ȣ���ϴ� ǥ���

	// �ٽ� 5. �Լ� ȣ�� ǥ������ �Ϲ�ȭ!!
	f1(10);			// ����� �ƴ� �Ϲ��Լ� �����ͷ� �Լ� ȣ��
	(dlg.*f2)(10);	// ��� �Լ� �����ͷ� �Լ� ȣ��!

	// C++17 ���� ���Ե� std::invoke() ���
	std::invoke(f1, 10);		// f1(10)
	std::invoke(f2, &dlg, 10);	// (dlg.*f2)(10);
}