#include "Array.hpp"

template<typename T>
Array<T>::Array(void)
{
	new T[];
}
template<typename T>
Array<T>::Array(unsigned int n)
{
	new T[n];
}
template<typename T>
Array<T>::Array(Array const &src)
{

}

		Array &operator=(Array const &rhs);
T& Array::operator[](unsigned int index);


