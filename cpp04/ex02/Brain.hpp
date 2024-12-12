#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
public:
						Brain();
						Brain( const Brain& other );
	Brain&				operator=(const Brain& other);
						~Brain();
	void				setIdea( std::string idea, int i);
	const std::string	getIdea(int i) const;

private:
	std::string _ideas[100];
};

#endif//BRAIN_HPP