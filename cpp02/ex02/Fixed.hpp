#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{

public:
				Fixed();
				Fixed( int const val );
				Fixed( float val );

				Fixed( const Fixed& val );
		Fixed& operator=( const Fixed& val );
				~Fixed();

		// comparison overloads
		bool	operator>( const Fixed& val ) const;
		bool	operator<( const Fixed& val ) const;
		bool	operator<=( const Fixed& val ) const;
		bool	operator>=( const Fixed& val ) const;
		bool	operator==( const Fixed& val ) const;
		bool	operator!=( const Fixed& val ) const;

		//arithmetic overloads
		Fixed	operator+( const Fixed& val ) const;
		Fixed	operator-( const Fixed& val ) const;
		Fixed	operator*( const Fixed& val ) const;
		Fixed	operator/( const Fixed& val ) const;

		//increment/decrement overloads
		Fixed&	operator++( void );
		Fixed	operator++( int );
		Fixed&	operator--( void );
		Fixed	operator--( int );

		//min/max

		static Fixed& min(Fixed& a, Fixed & b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);





		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
private:

	int					_fixedVal;
	static const int	_fractional = 8;

};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);


#endif