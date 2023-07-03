#include <iostream>

// constexpr - C++11 에서 도입
// => 함수 인자값을 컴파일 시간에 알수 있다면
//    함수 실행을 컴파일 할때 할수 있다는 의미

constexpr auto add(int a, int b)
{
	bool ret = std::is_constant_evaluated(); // C++20 에서 추가된 함수

	// constexpr 함수 안에서는 cout 을 사용할수는 없습니다.

	return std::pair<int, bool>(a + b, ret);
}
/*
int main()
{
	int x = 1, y = 2;

	int arr1[add(1, 2)]; // ok. add 호출이 컴파일 할때 수행. 
//	int arr2[add(x, y)]; // error. 인자 값을 컴파일 할때 알수 없다.
						 //        add() 함수를 컴파일 할때 수행 안됨.

	int ret1 = add(x, y);// ok. x, y 가 변수 지만, add() 호출을 사용하는
						// 문맥이 컴파일 시간을 요구하지 않음.
						// 그래서, add()가 실행시간에 호출

	int ret2 = add(1, 2);  // 컴파일 시간 ? 실행시간 ?
	

}
*/

int main()
{
	int x = 1, y = 2;

	auto ret1 = add(1, 2);
	std::cout << ret1.second << std::endl;


	auto ret2 = add(x, y);
	std::cout << ret2.second << std::endl;


	constexpr auto ret3 = add(1, 2);
	std::cout << ret3.second << std::endl;
}