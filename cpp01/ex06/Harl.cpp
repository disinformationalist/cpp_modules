#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "I cannot believe adding exta bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}
	
void	Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain( int i )
{

	Harlf fts[]  = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	str levels[] = { "DEBUG", "INFO", "WARNING", "ERROR"};

	for (; i < 4; i++)
	{
		std::cout << "[" << levels[i] << "]" << std::endl;
		(this->*fts[i])();
		std::cout << std::endl;
	}
}

void	Harl::filter( str level )
{
	int i;

	str levels[] = { "DEBUG", "INFO", "WARNING", "ERROR", "OFF"};
	i = 0;
	while (i < 5 && levels[i].compare(level))
		i++;
	
	switch (i)
	{
		case 0:
			this->complain(0);
			break ;
		case 1:
			this->complain(1);
			break ;
		case 2:
			this->complain(2);
			break ;
		case 3:
			this->complain(3);
			break ;
		case 4:
			std::cout << "Harl is off." << std::endl;
			break ;
		default:
			std::cerr << "[ Probably complaining about insignificant problems ] " << std::endl;
	}
}