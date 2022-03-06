#ifndef MUTANTSTACK_HPP_
# define MUTANTSTACK_HPP_

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack() {}
        MutantStack(const MutantStack& other) { *this = other; }
        ~MutantStack() {}
        
        MutantStack& operator=(const MutantStack& other)
        {
            std::stack<T>::operator=(other);
            return *this;
        }

        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin() { return this->c.begin(); }
        iterator end() { return this->c.end(); }

        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        const_iterator cbegin() const { return this->c.cbegin(); }
        const_iterator cend() const { return this->c.cend(); }

        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        reverse_iterator rbegin() { return this->c.rbegin(); }
        reverse_iterator rend() { return this->c.rend(); }

        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
        const_reverse_iterator crbegin() const { return this->c.crbegin(); }
        const_reverse_iterator crend() const { return this->c.crend(); }

};

#endif
