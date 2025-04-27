#include "ShrubberyCreationForm.hpp"
#include <fstream>

//ortho
ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("ShrubberyCreationForm", false, 145, 137), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
: AForm("ShrubberyCreationForm", false, 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
: AForm(other), _target(other._target)
{
	std::cout << "Shrub form Copy Constructor has been called." << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void	ShrubberyCreationForm::doIt() const
{
	std::ofstream outfile((_target + "_shrubbery").c_str());
	if (!outfile)
		return ;
	
	outfile << "         *      " << std::endl;
	outfile << "        * *     " << std::endl;
	outfile << "       * * *    " << std::endl;
	outfile << "      * * * *   " << std::endl;
	outfile << "     * * * * *  " << std::endl;
	outfile << "    * * * * * * " << std::endl;
	outfile << "        | |     " << std::endl;
	outfile << "       /   \\   " << std::endl << std::endl;


	outfile << "   {~ ~}                " << std::endl;
	outfile << "  {~ ~ ~} {~}   {-}     " << std::endl;
	outfile << " {~ ~} \\ {~ ~} {~ ~}   " << std::endl;
	outfile << "   \\__|/   \\__{~ ~ ~} " << std::endl;
	outfile << "       \\   //____\\//  " << std::endl;
	outfile << "   ~    \\ //           " << std::endl;
	outfile << " ~      | |       ~     " << std::endl;
	outfile << "  ~    /   \\  ~     ~  " << std::endl << std::endl;

	outfile.close();
}

std::string&	ShrubberyCreationForm::getTarget()
{
	return (_target);
}
