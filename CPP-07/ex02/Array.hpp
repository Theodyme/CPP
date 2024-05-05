#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
# include "Array.tpp"

template<class T>
class Array
{
	private:
		T* _array;
		unsigned int _size;
	public:
		Array();
		Array(unsigned int n);
		Array(Array const &src);
		unsigned int size() const;
		Array &operator=(Array const &rhs);
		T& Array::operator[](unsigned int index);

	class OutofRange : public std::exception
	{
		public:
			virtual const char* what() const throw() { return "out of bounds\n"; }

	};
};

# include "Array.tpp"

#endif
