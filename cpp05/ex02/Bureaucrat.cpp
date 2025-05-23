#include "Bureaucrat.hpp"

//orthodoxy

Bureaucrat::Bureaucrat() : _name("blank"), _grade(75) 
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	std::cout << "Bureaucrat " << _name << " created." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
	std::cout << "Bureaucrat Copy Constructor has been called." << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_grade = other._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << _name << " destroyed." << std::endl;
}

//overloads

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bur)
{
	os << bur.getName() << ", bureaucrat grade " << bur.getGrade();
	return (os);
}

//getters

std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

// inc and dec

void Bureaucrat::increment()
{
	if (_grade < 2)
		throw GradeTooHighException();
	_grade--;
	std::cout << "Bureaucrat " << _name << " promoted!" << std::endl;
}

void Bureaucrat::decrement()
{
	if (_grade > 149)
		throw GradeTooLowException();
	_grade++;
	std::cout << "Bureaucrat " << _name << " demoted:(" << std::endl;
}

//exceptions

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}