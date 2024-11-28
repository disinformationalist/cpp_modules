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
	void	complain( int i );
	void	filter( str );

private:
	
	typedef void	(Harl::*Harlf)( void );
			void	debug( void );
			void	info( void );
			void	warning( void );
			void	error( void );
};

#endif
/* [ WARNING ]
I think I deserve to have some extra bacon for free.
I've been coming for years whereas you started working here since last month.
[ ERROR ]
This is unacceptable, I want to speak to the manager now.
$> ./harlFilter "I am not sure how tired I am today..."
[ Probably complaining about insignificant problems ] */