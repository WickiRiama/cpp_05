/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:59:12 by mriant            #+#    #+#             */
/*   Updated: 2023/01/10 13:34:37 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h> 

#include "RobotomyRequestForm.hpp"
#include "colors.h"

//==============================================================================
// Constructors
//==============================================================================

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("robotomy", 72, 45,
													   "noTarget")
{
	srand (time(NULL));
	std::cout << "Robotomy default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("robotomy", 72,
																	 45, target)
{
	srand (time(NULL));
	std::cout << "Robotomy constructor called with target " << this->getTarget()
			  << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src.getName() + "_copy", 72, 45, src.getTarget())
{
	srand (time(NULL));
	*this = src;
	std::cout << "Shrubbery copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "Robotomy " << this->getName() << " destructor called"
			  << std::endl;
}

//==============================================================================
// Operators
//==============================================================================

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	(void) rhs;
	return *this;
}

//==============================================================================
// Functions
//==============================================================================

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	int randNb;
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
	std::cout << "* drilling noises * ";
	randNb = rand() %2;
	if (randNb)
		std::cout << this->getTarget() << " has been successfully robotomized"
				  << std::endl;
	else
		std::cout << "The robotomy of " << this->getTarget() << " has failed"
				  << std::endl;
}

