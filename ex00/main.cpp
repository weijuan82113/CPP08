#include <iostream> // for std::cout
#include <vector>   // for vector
#include <list>     // for std::list
#include <deque>    // for std::deque
#include <set>      // for std::set

#include "EasyFind.h"

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	//const test
	std::vector<int> vec(arr, arr+5);
    const std::list<int> lst(arr, arr+5);
    const std::deque<int> deq(arr, arr+5);
    const std::set<int> st(arr, arr+5);


	int value_to_find = 3;
	try
	{
		std::vector<int>::iterator change_it = ::easyfind(vec, value_to_find);
		*change_it = 4;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	value_to_find = 3;
	try
	{
		std::cout << "Vector: " << *::easyfind(vec, value_to_find) << std::endl;
		std::cout << "List: " << *::easyfind(lst, value_to_find) << std::endl;
		std::cout << "Deque: " << *::easyfind(deq, value_to_find) << std::endl;
		std::cout << "Set: " << *::easyfind(st, value_to_find) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}