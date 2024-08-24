#include "Span.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
//define the number of numbers
#define nums 150000
//define int of range from 1~max_range
#define max_range 200000
int main()
{
	std::srand(std::time(0));
	//intialize a vector of range 1~max_range
	std::vector<int> range;
	for(int i = 0; i < nums; i++)
	{
		int rand_int = 1 + max_range;
		while (rand_int > max_range)
			rand_int = 1+ rand()/((RAND_MAX + 1u)/max_range);
		range.push_back(rand_int);
	}

	Span sp(nums);
	sp.addNumbers(range.begin(), range.end());
	std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "longest span: " << sp.longestSpan() << std::endl;

	std::cout << "----verify----" << std::endl;
	std::vector<int> sorted_num = sp.getNumbers();
	std::sort(sorted_num.begin(), sorted_num.end());
	for (int i = 0; i < nums; i++)
	{
		std::cout << sorted_num[i] << "[" << sorted_num[i+1]-sorted_num[i] << "]" << sorted_num[i+1] << std::endl;
	}
	std::cout << "----verify----" << std::endl;

	return 0;
}