#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class Form
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

				Form();
				Form(const std::string name, bool isSigned, int gradeToSign, int gradeToExecute);
				Form(const Form& other);
	Form&		operator=(const Form& other);	
				~Form();


	void		beSigned(const Bureaucrat& );

	std::string getName() const;
	int			getGradeToSign() const;
	int			getGradeToExecute() const;
	bool		getIsSigned() const;

private:
		const std::string	_name;
		bool 				_isSigned;
		const int  			_gradeToSign;
		const int  			_gradeToExecute;
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif // FORM_HPP