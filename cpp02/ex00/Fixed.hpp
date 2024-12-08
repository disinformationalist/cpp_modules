#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{

public:
				Fixed();
				~Fixed();
				Fixed( const Fixed& fractional );
		Fixed& operator=( const Fixed& fractional );
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

private:

	int					_fixedVal;
	static const int	_fractional = 8;

};

#endif