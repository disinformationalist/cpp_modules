#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>


template <typename T>

class Array
{
public:
				Array();
				Array(unsigned int n);
				Array(const Array& other);
		Array&	operator=(const Array& other);
				~Array();
		T&		operator[](unsigned int i);
const	T&		operator[](unsigned int i) const;
				unsigned int size() const;
private:
	T*				data;
	unsigned int	_size;
};

//construct, copy assign, destruct

template <typename T>
Array<T>::Array(): data(NULL), _size(0)
{}

template <typename T>
Array<T>::Array(unsigned int n) : data(new T[n]()), _size(n)
{}

template <typename T>
Array<T>::Array(const Array& other) : data(new T[other._size]), _size(other._size)
{
	for (unsigned int i = 0; i < _size; ++i)
		data[i] = other.data[i];
}


template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		delete[] data;
		_size = other._size;
		data = new T[_size];
		for (unsigned int i = 0: i < _size; i++)
			data[i] = other.data[i];
	}
	return (*this);
}


template <typename T>
Array<T>::~Array() 
{
	delete[] data;
}



// getter for size

template <typename T>
unsigned int	Array<T>::size() const
{
	return _size;
}

//access, needs exception

template <typename T>
T& Array<T>::operator[](unsigned int i)
{
	return data[i];
}

template <typename T>
const T& Array<T>::operator[](unsigned int i) const
{
	return data[i];
}

/* //for testing in main

template <typename T, typename F>

void	iter(const T* arr, size_t len, F f)
{
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
} */

//#include "Array.tpp"//template file must be at bottom to see class first, templates parsed at compile, not linked after

#endif // ARRAY_HPP