#ifndef SPAN_HPP
#define SPAN_HPP


#include <exception>
#include <iostream>
#include <algorithm>
#include <vector>

class Span
{
	private:
		unsigned int _N;
		std::vector<int> _arr;
	public:
		Span();
		~Span();
		Span(unsigned int N);
		Span(const Span & copy);
		Span & operator=(Span const & right);

		void addNumber (const int & n);

		template <typename T>
		void addRange(T begin, T end)
		{
			if (std::distance(begin, end) > (_N - static_cast<int>(_arr.size())))
				throw NoSpaceException();
			while (begin != end)
			{
				_arr.push_back(*begin);
				begin++;
			}
		}

		unsigned int shortestSpan();
		unsigned int longestSpan();

		class NoSpaceException : public std::exception
		{
			public:
				const char * what() const throw();
		};
		class SmallsizeException : public std::exception
		{
			public:
				const char * what() const throw();
		};
		const std::vector<int> &getArr() const;
		void sort();
};

#endif