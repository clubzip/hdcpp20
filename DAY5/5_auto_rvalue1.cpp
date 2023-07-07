#include <vector>
#include <iostream>
#include <algorithm>

// �Ʒ� foo �� �ᱹ ���ø� �Դϴ�.
// �Ʒ� �ڵ� ��� ������ ������

void foo(auto& c)
{
	// c �ȿ��� c�� 1��° ��ҿ� ������ ���� �����ϰ� �ʹ�.
	// 
	// c.front()        : ������ ��ȯ �մϴ� ( T& )
	// remove 3��° ���� : const T& �� �޾Ƽ� ����մϴ�.
	// => ��, ��𼭵� 1��° ����� ���纻�� �������� �ʽ��ϴ�.

	// auto ret = std::remove(c.begin(), c.end(), c.front());


	// �ذ�å : c.front() �� ���ڷ� ������� ����, 
	//		   c.front() �� ���纻�� ���� ���ڷ� ����ϸ� �˴ϴ�.
	// �Ʒ� �ڵ�� �ƹ� ���� ������
	// => tmp �� ������ �Ѵٴ� ���� ���� �ʽ��ϴ�. 
	// => tmp �� �̸� �ִ� ��ü�̹Ƿ� {} ����� ���� �ı����� �ʽ��ϴ�.
//	auto tmp = c.front();
//	auto ret = std::remove(c.begin(), c.end(), tmp);


	// ���� ���� �ذ�å
	// => c.front() �� ������ lvalue(�̸��ִ� ��ü)�� ������ ����
	//    rvalue(�̸����� ��ü, �ӽð�ü)�� ����� ����ϴ� ���� ����.
	
//	auto ret = std::remove(c.begin(), c.end(), int( c.front() ) );



	// �׷���, �� �ڵ�� c.front() �� int Ÿ���̶�� ������ �ڵ� �Դϴ�.
	// => �� �ڵ带 ��� Ÿ������ �Ϲ�ȭ �Ϸ��� ??
	// C++23 ����
	//using T = decltype(c.front()); // c.front()�� ���� ��ȯ�̹Ƿ� int& �˴ϴ�.

//	using T = std::decay_t<decltype(c.front())>; // const, reference ����
//	auto ret = std::remove(c.begin(), c.end(), T(c.front()));

	// C++23 ����
	// auto(ǥ����) �Ǵ� auto{ǥ����}
	// => ǥ���İ� ���� ���� ������ prvalue �� ����� ǥ����
	// => �Ʒ� ���������� auto(c.front()) �� �ᱹ literal 1 �Դϴ�.
	// => VS ���� ���� ����. g++13.1 �� ����
	auto ret = std::remove(c.begin(), c.end(), auto{ c.front() } ) ;

	c.erase(ret, c.end());
}





int main()
{
	std::vector v{1, 2, 3, 1, 2, 3, 1, 2, 3, 1};

	foo(v);

	for (auto e : v)
		std::cout << e << ", ";

	std::cout << std::endl;
}