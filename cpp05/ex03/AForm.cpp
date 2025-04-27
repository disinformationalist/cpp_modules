#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("random form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)  
{
}

AForm::AForm(const std::string name, bool isSigned, const int gradeToSign, const int gradeToExecute)
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

	std::cout << "AForm " << _name << " created." << std::endl;
}

AForm::AForm(const AForm& other)
: _name(other._name), 
_isSigned(other._isSigned),
_gradeToSign(other._gradeToSign), 
_gradeToExecute(other._gradeToExecute)
{
	std::cout << "AForm Copy Constructor has been called." << std::endl;
}

AForm&	AForm::operator=(const AForm& other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}	

AForm::~AForm()
{
	std::cout << "AForm " << _name << " destroyed." << std::endl;
}

//getters

std::string	AForm::getName() const
{
	return (_name);
}

int		AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int		AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

bool	AForm::getIsSigned() const
{
	return (_isSigned);
}

//overloads

std::ostream& operator<<(std::ostream& os, const AForm& f)
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

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high"; 
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Form not Signed";
}

//sign

void	AForm::beSigned(const Bureaucrat& signer)
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

//exec

void	AForm::execute(const Bureaucrat& executor) const
{
	if (!getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
	doIt();//call action of the derived, this is the virtual in base class
	std::cout << executor.getName() << " executed " << _name << std::endl;
}