#include "Span.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
//define the number of numbers
#define nums 150000
//define int of range from 1~max_range
#define max_range 200000

#include <limits>

int main()
{
	//----test nums & max_range------

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
	//show the shortest & longest span
	std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "longest span: " << sp.longestSpan() << std::endl;
	//type ./Span > test.txt to verify the outputfile
	std::cout << "----verify----" << std::endl;
	std::vector<int> sorted_num = sp.getNumbers();
	std::sort(sorted_num.begin(), sorted_num.end());
	for (int i = 0; i < nums; i++)
	{
		std::cout << sorted_num[i] << "[" << sorted_num[i+1]-sorted_num[i] << "]" << sorted_num[i+1] << std::endl;
	}
	std::cout << "----verify----" << std::endl;

	//----test nums & max_range------


	//-----test INI_MAX & INT_MIN-----

	// std::vector<int> limit_range;
	// limit_range.push_back(std::numeric_limits<int>::max());
	// limit_range.push_back(std::numeric_limits<int>::min());
	// Span limit_sp(2);
	// limit_sp.addNumbers(limit_range.begin(), limit_range.end());
	// std::cout << "shortest span: " << limit_sp.shortestSpan() << std::endl;
	// std::cout << "longest span: " << limit_sp.longestSpan() << std::endl;

	//-----test INI_MAX & INT_MIN-----

	return 0;
}