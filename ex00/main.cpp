#include "easyfind.hpp"

int main()
{
	std::vector<int> vec;
	vec.push_back(4);
	vec.push_back(7);
	vec.push_back(123);
	vec.push_back(0);

	try
	{
		std::cout << *easyfind(vec, 2) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << *easyfind(vec, 7) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << *easyfind(vec, 0) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}