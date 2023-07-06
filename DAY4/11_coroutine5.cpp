#include <iostream>
#include <coroutine>

#define log() std::cout << __func__ << std::endl 

// C++ �ڷ�ƾ�� ��� �����ϴ°� ?
// ������ ���캸�� �ڵ�..
// �ּ��� �� �����غ�����..

// �ٽ� : coroutine framework �� ���� �����Ҷ�
// 1. promise_type �ȿ� operator new() �� ������ ����ϰ�
// 2. ������ global new ����մϴ�.


class Generator
{
public:

	class promise
	{
	public:
		std::suspend_always initial_suspend() 
		{ 
			log();
			return {}; 
		}
		std::suspend_always final_suspend() noexcept { return {}; }
		Generator get_return_object() { return {}; };
		void unhandled_exception() {}
		void return_void() {}

		void* operator new(std::size_t sz)
		{
			void* p = ::operator new(sz);
			printf("new : %p, %d bytes\n", p, sz);
			return p;
		}
		void operator delete(void* p) noexcept
		{
			printf("delete : %p\n", p);
			::operator delete(p);
		}
	};
	using promise_type = promise;
};
Generator foo()
{
	int x[100];  // 400 byte.. coroutine framework ũ�Ⱑ
	x[0] = 0;	 // 400����Ʈ ����
	// �Լ� �ȿ� "co_await" ���� Ű���尡 ������ �����Ϸ��� �Ʒ� �ڵ带 �����մϴ�.
	//---------------------------------------------
	// 1. �ڷ�ƾ frame �� ���� �����մϴ�.
	// => sizeof(��������) + sizeof(��ȯŸ��::promise_type) + ��Ÿ ���� 
	//		 => ���������� ��� 200 ~ 400 byte ���� �����Ϸ����� �ٸ��ϴ�.

	// 2. promise_type �� ������ ȣ��

	// 3. promise_type �� get_return_object()�� ȣ���ؼ� Generator ����

	// 4. promise_type �� initial_suspend() ȣ��

	// 5. (3) ���� ������ ��ü�� ��ȯ.. 
	//    => ��, ���⼭ main ���� ��ȯ




	//---------------------------------------------
	std::cout << "foo 1" << std::endl;

	co_await std::suspend_always{};

	std::cout << "foo 2" << std::endl;
}



int main()
{
	foo();
}
