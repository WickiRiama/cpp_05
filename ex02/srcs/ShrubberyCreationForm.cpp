/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:56:54 by mriant            #+#    #+#             */
/*   Updated: 2022/12/09 17:43:19 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>

#include "ShrubberyCreationForm.hpp"
#include "colors.h"

//==============================================================================
// Constructors
//==============================================================================

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("shrubbery", 145),
													 _requestedExecGrade(137),
													 _target("noTarget")
{
	std::cout << "Shrubbery default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("shrubbery", 145),
																   _requestedExecGrade(137),
																   _target(target)
{
	std::cout << "Shrubbery constructor called with target " << this->_target
			  << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src.getName() + "_copy", 145),
																				 _requestedExecGrade(137), 
																				 _target(src.getTarget())
{
	*this = src;
	std::cout << "Shrubbery copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "Shrubbery " << this->getName() << " destructor called"
			  << std::endl;
}

//==============================================================================
// Operators
//==============================================================================

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	(void) rhs;
	return *this;
}

//==============================================================================
// Functions
//==============================================================================

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getSignedStatus() == 0)
		throw ShrubberyCreationForm::FormNotSignedException();
	else if (executor.getGrade() > this->_requestedExecGrade)
		throw ShrubberyCreationForm::GradeTooLowException();
	else
		this->drawTrees(this->_target);
}

void ShrubberyCreationForm::drawTrees(std::string target) const
{
	std::ofstream file;
	std::string fileName = target + "_shrubbery";

	file.exceptions(std::ofstream::failbit | std::ofstream::badbit);
	try
	{
		file.open(fileName.c_str(), std::ios::trunc);
		file << "               ,@@@@@@@,\n"
			 << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
			 << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
			 << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88\'\n"
			 << "   %&&%&%&/%&&%@@\\@@/ /@@@8888888888'\n"
			 << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88\'\n"
			 << "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
			 << "       |o|        | |         | |\n"
			 << "       |.|        | |         | |\n"
			 << "jgs \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n"
			 << "\n"
			 << "------------------------------------------------\n"
			 << "Thank you for visiting https://asciiart.website/\n"
			 << "This ASCII pic can be found at\n"
			 << "https://asciiart.website/index.php?art=plants/trees" << std::endl;
		file.close();
	}
	catch (std::ofstream::failure e)
	{
		std::cout << RED << e.what() << std::endl;
		return;
	}
	catch (std::exception e)
	{
		std::cout << RED << e.what() << std::endl;
		return;
	}

}

int ShrubberyCreationForm::getRequestedExecGrade(void) const
{
	return this->_requestedExecGrade;
}


std::string ShrubberyCreationForm::getTarget(void) const
{
	return this->_target;
}