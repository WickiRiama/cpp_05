/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:56:54 by mriant            #+#    #+#             */
/*   Updated: 2023/01/10 14:20:43 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>

#include "ShrubberyCreationForm.hpp"
#include "colors.h"

//==============================================================================
// Constructors
//==============================================================================

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("shrubbery", 145,
													 137, "noTarget")
{
	std::cout << "Shrubbery default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("shrubbery", 145,
																   137, target)
{
	std::cout << "Shrubbery constructor called with target " << this->getTarget()
			  << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src.getName() + "_copy", 145, 137, src.getTarget())
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
	this->setSignedStatus(rhs.getSignedStatus());
	return *this;
}

//==============================================================================
// Functions
//==============================================================================

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	try
	{
		this->checkRequirements(executor);
	}
	catch(AForm::FormNotSignedException &e)
	{
		throw AForm::FormNotSignedException();
	}
	catch (AForm::GradeTooLowException &e)
	{
		throw AForm::GradeTooLowException();
	}
	this->drawTrees();
}

void ShrubberyCreationForm::drawTrees(void) const
{
	std::ofstream file;
	std::string fileName = this->getTarget() + "_shrubbery";

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
