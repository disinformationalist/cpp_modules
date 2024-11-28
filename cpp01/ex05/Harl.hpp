#ifndef HARL_HPP
# define HARL_HPP

#include <string>
#include <iostream>

typedef std::string str;

class Harl
{
public:
			Harl();
			~Harl();
	void	complain( str );

private:
	
	typedef void	(Harl::*Harlf)( void );
			void	debug( void );
			void	info( void );
			void	warning( void );
			void	error( void );
};

#endif