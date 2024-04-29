#ifndef ITER_HPP
# define ITER_HPP

# include <cstdlib>
#include <string>
#include <iostream>

template<typename T>
void iter(T *array, size_t size, void (*f)(T))
{
	for (size_t i = 0; i < size; i++)
		(*f)(array[i]);
}

template<typename T>
void printer(T a)
{
	std::cout << a << std::endl;
}

template<typename T>
void increment(T a)
{
	a += 1;
	std::cout << a << std::endl;
}

#endif
