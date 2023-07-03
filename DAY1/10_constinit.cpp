
// C++11 constexpr ��� : �ݵ�� �ʱⰪ�� ������ �ð��� �˾ƾ� �ϴ� "���".
// C++20 constinit     : �ݵ�� �ʱⰪ�� ������ �ð��� �˾ƾ� �ϴ� "����".
int value1 = 10;

constexpr int c1 = value1; // error
constexpr int c2 = 10;     // ok

constinit int c3 = value1; // error
constinit int c4 = 10;	   // ok


int main()
{
	c2 = 20; // error. c2 �� ���
	c4 = 20; // ok..   c4 �� ����!!

	// ��, constinit �� �������� �տ� �ٿ���..
	// �ݵ�� �ʱⰪ�� ������ �ð��� �˾ƾ� �Ѵٴ� ��!

	// => C++�� ������ ���ø� ���� ���� ����ϰ� �Ǿ
	// => ������ �ð��� �ϴ� ���� �������ϴ�.
	// => �׷��� ������ �ð��� �䱸�ϴ� ������ ���� ���� ���ϴ�.
}
// C++11 : constexpr ����
// C++20 : consteval, constinit ����