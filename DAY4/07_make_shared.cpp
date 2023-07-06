#include <iostream>
#include <memory>

int goo() { return 10; }
void foo(std::shared_ptr<int> sp, int n) {}

int main()
{
	// C++ ǥ�� ����Ʈ ������ ����
	// => ���� new ��������
	// => std::make_shared<> �� ����ϴ� ���� �����ϴ�.

	std::shared_ptr<int> p1(new int);				   // bad
	std::shared_ptr<int> p2 = std::make_shared<int>(); // good

	std::unique_ptr<int> p3(new int);				   // bad
	std::unique_ptr<int> p2 = std::make_unique<int>(); // good



	// �� make_shared �� ���� ���� ?
	// => �Ʒ� �ڵ忡�� (A), (B), (C)��  ����Ǵ� ������ ���� �Ǿ������ʽ��ϴ�.
	// => B, A, C ������ ����Ǹ� �����մϴ�.
	// => B, C, A ������ ����ǰ�, goo() ���� ���� ������
	//				=> B ���� �Ҵ��� �޸𸮴� ������ �˴ϴ�.

	// �ٽ� : �ڿ��� �Ҵ��ϸ� ��� �ٸ����� �ϱ� ���� �ݵ��
	//       �ڿ� ���� ��ü(����Ʈ������)�� �Ѱܾ� �մϴ�.
	//       �߰��� �ٸ� �۾��� �߻��ϸ� �ȵ˴ϴ�.
	foo( std::shared_ptr<int>(new int), goo() );
	//		(A)					(B)      (C)


	// �׷���. �Ʒ� ó�� �ϸ� �׻� �����մϴ�.
	// std::make_shared<int>() : 1. ���������� new int �ϰ�
	//							 2. �Ҵ�� �ּҸ� �����ϴ� ����Ʈ�����͹�ȯ
	foo(std::make_shared<int>(), goo());
	//	    (A)					 (B) 










	// ����Ʈ ������ �迭 ���� ���
	std::unique_ptr<int> up1(new int);	
	std::unique_ptr<int> up2(new int[10]);

	std::shared_ptr<int> sp1(new int);	
	std::shared_ptr<int> sp2(new int[10]);
			
}
