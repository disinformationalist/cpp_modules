#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("random form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)  
{
}

Form::Form(const std::string name, bool isSigned, const int gradeToSign, const int gradeToExecute)
: _name(name), 
_isSigned(isSigned),
_gradeToSign(gradeToSign), 
_gradeToExecute(gradeToExecute)
{
	if (gradeToSign > 150)
		throw GradeTooLowException();
	else if (gradeToSign < 1)
		throw GradeTooHighException();

	if (gradeToExecute > 150)
		throw GradeTooLowException();
	else if (gradeToExecute < 1)
		throw GradeTooHighException();

	std::cout << "Form " << _name << " created." << std::endl;
}

Form::Form(const Form& other)
: _name(other._name), 
_isSigned(other._isSigned),
_gradeToSign(other._gradeToSign), 
_gradeToExecute(other._gradeToExecute)
{
	std::cout << "Form Copy Constructor has been called." << std::endl;
}

Form&	Form::operator=(const Form& other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}	

Form::~Form()
{
	std::cout << "Form " << _name << " destroyed." << std::endl;
}

//getters

std::string	Form::getName() const
{
	return (_name);
}

int		Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int		Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

bool	Form::getIsSigned() const
{
	return (_isSigned);
}

//overloads

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	std::string status;

	if (f.getIsSigned())
		status = "\033[32msigned\033[0m";
	else
		status = "\033[31mnot signed\033[0m"; 
	os << f.getName() << ", form, " << status 
	   << ", grade to sign: " << f.getGradeToSign() 
	   << ", grade to execute: " << f.getGradeToExecute()
	   << std::endl;
	return (os);
}

//exceptions

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade too high"; 
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

//sign

void	Form::beSigned(const Bureaucrat& signer)
{
	std::string s_name = signer.getName();
	
	if (signer.getGrade() > _gradeToSign)
		throw GradeTooLowException();
    else
	{
		std::cout << s_name << " signed " << _name << std::endl;
		_isSigned = true;
	}
}