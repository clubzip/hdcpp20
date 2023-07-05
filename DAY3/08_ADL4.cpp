#include <iostream>

namespace mystd
{
	class string {};

	template<typename T> void max(const T& a, const T& b) 
	{
		std::cout << "std::max" << std::endl;
	}

	// C++20
	namespace ranges
	{
		/*
		template<typename T> void max(const T& a, const T& b)
		{
			std::cout << "std::ranges::max" << std::endl;
		}
		*/
		struct MaxFn
		{
			template<typename T> 
			void operator()(const T& a, const T& b)
			{
				std::cout << "std::ranges::max" << std::endl;
			}
		};
		MaxFn max; // max �� �Լ��� �ƴ� �Լ� ��ü
	}
}

int main()
{
	mystd::string s1;
	mystd::string s2;

	mystd::max(s1, s2);			// C++98
	mystd::ranges::max(s1, s2);	// C++20 
	
	// �Ʒ� �ڵ带 ������ ���ô�.
	using namespace mystd::ranges; // C++20�� ����ϰڴٴ� �������� open
	max(s1, s2);	// max �� �Լ� ��� ����.!
					// max �� �Լ� ��ü��� ���� �ƴ�.


}