#include "span.hpp"
#include <cstdlib>

int main()
{
	{
		Span sp = Span(5);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	{
		Span	big = Span(10000);
		std::vector<int> index;
		std::srand(time(NULL));
		for (int i = 0; i < 10000; i++)
		{
			int input = std::rand() % 100000;
			index.push_back(input);
		}
		big.addRange(index.begin(), index.end());
		big.sort();
		std::vector<int>::const_iterator iter;
		for(iter = (big.getArr()).begin(); iter != (big.getArr()).end(); iter++)
		{
			std::cout << *iter << " " << std::endl;
		}
		std::cout << "shortestSpan : " << big.shortestSpan() << std::endl;
		std::cout << "longestSpan : " << big.longestSpan() << std::endl;
	}

	{
		Span middle = Span(10);
		srand(time(NULL));
		for (int i = 0; i < 10; i++)
		{
			int input = rand() % 1000;
			middle.addNumber(input);
		}
		middle.sort();
		std::vector<int>::const_iterator iter;
		for(iter = (middle.getArr()).begin(); iter != (middle.getArr()).end(); iter++)
		{
			std::cout << *iter << " " << std::endl;
		}
		std::cout << "shortestSpan : " << middle.shortestSpan() << std::endl;
		std::cout << "longestSpan : " << middle.longestSpan() << std::endl;
		std::cout << *std::max_element(middle.getArr().begin(), middle.getArr().end()) << std::endl;
		std::cout << *std::min_element(middle.getArr().begin(), middle.getArr().end()) << std::endl;
	}

	{
		try
		{
			Span small(1);
			small.addNumber(10);
			small.addNumber(11);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	
}
