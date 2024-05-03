#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <stack>

template <class T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() { };
		MutantStack(MutantStack const &src) { *this = src; };
		~MutantStack() { };
		MutantStack &operator=(MutantStack const &rhs) { (void)rhs; return *this; };

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin() { return this->c.begin(); };
		iterator end() { return this->c.end(); };
};

#endif
