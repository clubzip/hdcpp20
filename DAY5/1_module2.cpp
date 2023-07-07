// C++20 Big4 : Concept, Coroutine, Module <= 문법의 변화
//              Range 라이브러리  <= STL 의 변화

// C++20 : 모듈 문법을 도입
// C++23 : 모든 표준 라이브러리의 모듈 버전을 제공

import std;
import mymath;

int main()
{
	int n = add(1, 2);

	std::cout << n << std::endl;

	Point p(1, 2);
	p.print();
}

