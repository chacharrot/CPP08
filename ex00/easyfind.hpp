#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <vector>
#include <list>
#include <iostream>

class FindException : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return "I can't find it";
		}
};

template <typename T>
typename T::iterator easyfind(T &cont, const int &num)
{
	typename T::iterator res;
	res = std::find(cont.begin(), cont.end(), num);
	if (res == cont.end())
		throw FindException();
	return res;
}

#endif