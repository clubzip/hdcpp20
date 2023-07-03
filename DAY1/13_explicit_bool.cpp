#include <type_traits>

template<typename T> class Value
{
	T value;
public:	
	// explicit ������ : C++98 ����
	//					���� �ʱ�ȭ�� �����ϰ� ���� �ʱ�ȭ�� ����Ҽ� ����.
//	explicit Value(T arg) {}

	// C++20 ���� ���Ǻ� explicit �� ���� �˴ϴ�.
//	explicit(false) Value(T arg) {}
//	explicit(true) Value(T arg) {}

	// �����δ� �Ʒ� ó�� T�� Ư¡�� ���� explicit ���� ���θ� �����Ҷ� ���
	explicit(std::is_integral_v<T>) Value(T arg) {}
};

int main()
{
	// 
	Value v1{ 123 };	// direct initialization : = �� ���� ��
	Value v2 = { 123 };	// copy initialization   : = �� �ִ� ��

	Value v3{ 3.4 };
	Value v4 = { 3.4 }; // ok.. �Ǽ� �̹Ƿ� explicit �ƴ�.
}
