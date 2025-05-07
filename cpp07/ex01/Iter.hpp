#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>
#include <iostream>


template <typename T, typename F>

void	iter(T* arr, size_t len, F f)
{
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
}

template <typename T, typename F>

void	iter(const T* arr, size_t len, F f)
{
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
}


//templated functions

template <typename T>

void add_two(T& x)
{
	x += 2;
}

template <typename T>

void	print_val(const T& val)
{
	std::cout << val << std::endl;
}

#endif // ITER_HPP