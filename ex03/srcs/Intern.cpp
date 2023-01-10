/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:12:58 by mriant            #+#    #+#             */
/*   Updated: 2023/01/10 16:28:54 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

//==============================================================================
// Constructors
//==============================================================================

Intern::Intern(void)
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(Intern const &src)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = src;
}

Intern::~Intern(void)
{
	std::cout << "Intern destructor called" << std::endl;
}

//==============================================================================
// Operators
//==============================================================================

Intern &Intern::operator=(Intern const &rhs)
{
	(void) rhs;
	return *this;
}

//==============================================================================
// Functions
//==============================================================================

AForm *Intern::makeShrubberyCreationForm(std::string target) const
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomyRequestForm(std::string target) const
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidentialPardonForm(std::string target) const
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	makeFunction funcTab[] = {&Intern::makeShrubberyCreationForm,
						  &Intern::makeRobotomyRequestForm,
						  &Intern::makePresidentialPardonForm};
	std::string nameTab[] = {"shrubbery", "robotomy", "pardon"};
	AForm *result;

	for (int i = 0; i < 3; i++)
	{
		if (name == nameTab[i])
		{
			result = (this->*funcTab[i])(target);
			return result;
		}
	}
	std::cout << name << " is not a form type, the intern can not make it"
			  << std::endl;
	return NULL;
}
