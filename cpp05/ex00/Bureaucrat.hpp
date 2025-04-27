#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{

public:
	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw();
	};

				Bureaucrat();			
				Bureaucrat(std::string name, int grade);
				Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
				~Bureaucrat();

	std::string getName() const;
	int			getGrade() const;
	void		increment();
	void		decrement();

private:

	const std::string	_name;
	int					_grade;// 1 - 150, 1 highest, 150 lowest, incrementing goes toward 1, decrementing goes toward 150
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bur);

#endif// BUREAUCRAT_HPP
