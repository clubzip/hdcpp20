#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>



int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	counted_iterator ci(v.begin(), 5);

	while (ci != std::default_sentinel)
	{
		std::cout << *ci << std::endl;
		++ci;
	}
}


