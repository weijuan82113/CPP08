#ifndef EASYFIND_H_
 #define EASYFIND_H_

#include <algorithm> //for std::find

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw (std::out_of_range("out of range!"));
	return it;
};

template <typename T>
typename T::const_iterator easyfind(const T& container,const int value)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw (std::out_of_range("out of range!"));
	return it;
};

#endif