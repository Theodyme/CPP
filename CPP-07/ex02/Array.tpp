#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "Array.hpp"

template<class T>
Array<T>::Array()
{
    _array = new T[0];
    _size = 0;
}

template<class T>
Array<T>::Array(unsigned int n)
{
    _array = new T[n];
    _size = n;
}

template<class T>
Array<T>::Array(const Array<T> &src)
{
    this->_array = new T[src._size];
	this->_size = src._size;
	for (int i = 0; i < this->_size; i++)
		this->_array[i] = src->_array[i];
}

template<class T>
unsigned int Array<T>::size() const
{
	return this->_size;
}

template<class T>
Array<T> &Array<T>::operator=(const Array<T> &rhs)
{
	delete[] this->_array;
	this->_array = new T[rhs._size];
	this->_size = src._size;
	for (int i = 0; i < this->_size; i++)
		this->_array[i] = rhs->_array[i];
	return *this;
}

template<class T>
T &Array<T>::operator[](unsigned int index)
{
	if (index < this->_size)
		return this->_array[index];
	else
		throw std::OutofRange();
}

#endif