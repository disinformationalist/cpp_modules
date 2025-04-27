#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class AForm
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
	class FormNotSignedException : public std::exception
	{
	public:
		const char* what() const throw();	
	};

					AForm();
					AForm(const std::string name, bool isSigned, int gradeToSign, int gradeToExecute);
					AForm(const AForm& other);
	AForm&			operator=(const AForm& other);	
	virtual 		~AForm();

	void			beSigned(const Bureaucrat& );

	void			execute(const Bureaucrat& executor) const;

	virtual void	doIt() const = 0;
//protected://for derived access

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

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif // AFORM_HPP