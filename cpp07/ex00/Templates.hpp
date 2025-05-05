#ifndef TEMPLATES_HPP
# define TEMPLATES_HPP

template <typename T>

inline void	swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>

inline const T&	min(const T& a, const T& b)
{
	return (a <= b)? a : b;
}

template <typename T>

inline const T&	max(const T& a, const T& b)
{
	return (a >= b)? a : b;
}

#endif // TEMPLATES_HPP