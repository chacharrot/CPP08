#include "span.hpp"

Span::Span() : _N(0)
{}

Span::~Span()
{}

Span::Span(unsigned int N) : _N(N)
{}

Span::Span(const Span & copy) : _N(copy._N)
{
	this->_arr.clear();
	this->_arr = copy._arr;
}

Span & Span::operator=(const Span &other)
{
	if (this == &other)
		return (*this);
	this->_N = other._N;
	this->_arr.clear();
	this->_arr = other._arr;

	return *this;
}

void Span::addNumber(const int &n)
{
	if (this->_arr.size() >= this->_N)
		throw NoSpaceException();
	this->_arr.push_back(n);
}

unsigned int Span::longestSpan()
{
	if (this->_arr.size() < 2)
		throw SmallsizeException();
	return (std::abs(*std::max_element(_arr.begin(), _arr.end()) - *std::min_element(_arr.begin(), _arr.end())));
}

unsigned int Span::shortestSpan()
{
	if (this->_arr.size() < 2)
		throw SmallsizeException();
	std::vector<int>::iterator t1 = _arr.begin();
	std::vector<int>::iterator t2 = t1;
	t2++;
	int r = std::abs(*t2 - *t1);
    while (++t1 < _arr.end() && ++t2 < _arr.end())
	{
        if (std::abs(*t2 - *t1 ) < r)
            r = std::abs(*t2 - *t1);
    }
	return (r);
}

const char * Span::SmallsizeException::what() const throw()
{
	return "there is too few elements";
}

const char * Span::NoSpaceException::what() const throw()
{
	return "there is no space in container";
}
const std::vector<int> &Span::getArr() const
{
	return this->_arr;
}

void Span::sort()
{
	std::sort(_arr.begin(), _arr.end());
}