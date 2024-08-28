#include <vector>   // for vector
#include <list>     // for std::list
#include <deque>    // for std::deque
#include <set>      // for std::set
#include <iterator> // for std::iterator

#include "EasyFind.h"

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
//------non-const test------

	std::vector<int> vec(arr, arr+5);
	int value_to_change = 3;
	//-----use easyfind to change a value by iterator
	try
	{
		std::vector<int>::iterator change_it = easyfind(vec, value_to_change);
		*change_it = 4;
		std::cout << "after changing value by easyfind() \n <vec>" << std::endl;
		printElement(vec.begin(), vec.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	int value_to_find = 3;
	try
	{
		std::cout << "value_to_find: " << value_to_find << std::endl;
		std::cout << "Vector: " << *easyfind(vec, value_to_find) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

//------non const test------


//------const test------
	const std::vector<int> const_vec(arr, arr+5);
    const std::list<int> const_lst(arr, arr+5);
    const std::deque<int> const_deq(arr, arr+5);
    const std::set<int> const_st(arr, arr+5);

	//----print element in each data type----

	std::cout << "<const_vec>" << std::endl;
	printElement(const_vec.begin(), const_vec.end());
	std::cout << "<const_lst>" << std::endl;
	printElement(const_lst.begin(), const_lst.end());
	std::cout << "<const_deq>" << std::endl;
	printElement(const_deq.begin(), const_deq.end());
	std::cout << "<const_st>" << std::endl;
	printElement(const_st.begin(), const_st.end());

	//----print element in each data type----

	//----test easyfind in const data type----
	try
	{
		std::cout << "Print finded value: " << std::endl;
		std::cout << "Vector: " << *easyfind(const_vec, value_to_find) << std::endl;
		std::cout << "List: " << *easyfind(const_lst, value_to_find) << std::endl;
		std::cout << "Deque: " << *easyfind(const_deq, value_to_find) << std::endl;
		std::cout << "Set: " << *easyfind(const_st, value_to_find) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	//try to change the easyfind()'s return value
	// try
	// {
	// 	int try_change_value = 1;
	// 	std::vector<int>::const_iterator const_it = ::easyfind(const_vec, value_to_find);
	// 	*const_it = try_change_value;
	// 	std::cout << *const_it << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }

	//----test easyfind in const data type----
//------const test------

	return 0;
}