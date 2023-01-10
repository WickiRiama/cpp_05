/* ************************************************************************** */
/*                                                                         ShrubberyCreation   */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:42:18 by mriant            #+#    #+#             */
/*   Updated: 2023/01/10 13:42:21 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "colors.h"

//==============================================================================
// Constructors
//==============================================================================

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("pardon", 25, 5,
													   "noTarget")
{
	std::cout << "Presidential pardon default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("pardon", 25,
																	 5, target)
{
	std::cout << "Presidential pardon constructor called with target " << this->getTarget()
			  << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm(src.getName() + "_copy", 25, 5, src.getTarget())
{
	*this = src;
	std::cout << "Presidential pardon copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "Presidential pardon " << this->getName() << " destructor called"
			  << std::endl;
}

//==============================================================================
// Operators
//==============================================================================

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	this->setSignedStatus(rhs.getSignedStatus());
	return *this;
}

//==============================================================================
// Functions
//==============================================================================

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	try
	{
		this->checkRequirements(executor);
	}
	catch (AForm::FormNotSignedException &e)
	{
		throw AForm::FormNotSignedException();
	}
	catch (AForm::GradeTooLowException &e)
	{
		throw AForm::GradeTooLowException();
	}
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox"
			  << std::endl;
}

