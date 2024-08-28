#ifndef EASYFIND_H_
 #define EASYFIND_H_

#include <algorithm> //for std::find
#include <iostream> // for std::cout

template <typename T>
static typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw (std::out_of_range("out of range!"));
	return it;
};

template <typename T>
static typename T::const_iterator easyfind(const T& container, int value)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw (std::out_of_range("out of range!"));
	return it;
};

template <typename Iterator>
static void printElement(Iterator begin, Iterator end)
{
	for (Iterator it = begin; it != end; it++)
	{
		typename Iterator::value_type element = *it;
		std::cout << element << " ";
	}
	std::cout << std::endl;
}



#endif