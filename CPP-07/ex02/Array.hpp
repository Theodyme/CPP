#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
# include "Array.tpp"

template<typename T>
class Array
{
	private:
	public:
		Array();
		Array(unsigned int n);
		Array(Array const &src);
		Array &operator=(Array const &rhs) { }
};


#endif
