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