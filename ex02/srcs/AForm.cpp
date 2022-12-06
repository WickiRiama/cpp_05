/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:27:44 by mriant            #+#    #+#             */
/*   Updated: 2022/12/06 17:33:32 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

//==============================================================================
// Constructors
//==============================================================================

AForm::AForm(void) : _name("unnamed_form"), _signedStatus(0), _requiredGrade(150)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string name, int requiredGrade) : _name(name), _signedStatus(0),
												  _requiredGrade(requiredGrade)
{
	if (requiredGrade > 150)
		throw AForm::GradeTooLowException();
	else if (requiredGrade < 1)
		throw AForm::GradeTooHighException();
	std::cout << "AForm constructor called with name " << this->_name
			  << " and required grade " << this->_requiredGrade << std::endl;
}

AForm::AForm(AForm const &src) : _name(src.getName() + "_copy"),
							  _requiredGrade(src.getRequiredGrade())
{
	*this = src;
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm::~AForm(void)
{
	std::cout << "AForm destructor called" << std::endl;
}

//==============================================================================
// Operators
//==============================================================================

AForm &AForm::operator=(AForm const &rhs)
{
	if (this != &rhs)
	{
		this->_signedStatus = rhs.getSignedStatus();
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, AForm const &rhs)
{
	o << rhs.getName() << ", form, requires at least grade "
	  << rhs.getRequiredGrade() << " to be signed";
	if (rhs.getSignedStatus())
		o << ", signed";
	else
		o << ", not signed";
	return o;
}

//==============================================================================
// Functions
//==============================================================================

std::string AForm::getName(void) const
{
	return this->_name;
}

bool AForm::getSignedStatus(void) const
{
	return this->_signedStatus;
}

int AForm::getRequiredGrade(void) const
{
	return this->_requiredGrade;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_requiredGrade && !this->_signedStatus)
	{
		this->_signedStatus = 1;
	}
	else if (!this->_signedStatus)
		throw AForm::GradeTooLowException();
	else
		throw AForm::AlreadySignedException();
}