/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:27:44 by mriant            #+#    #+#             */
/*   Updated: 2023/01/10 14:20:04 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

//==============================================================================
// Constructors
//==============================================================================

AForm::AForm(void) : _name("unnamed_form"), _signedStatus(0),
					 _requiredSignGrade(150), _requiredExecGrade(150),
					 _target("no_target")
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string name, int signGrade, int execGrade, std::string target)
 : _name(name),	_signedStatus(0), _requiredSignGrade(signGrade), 
   _requiredExecGrade(execGrade), _target(target)
{
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
	else if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	std::cout << "AForm constructor called with name " << this->_name
			  << ", sign grade " << this->_requiredSignGrade 
			  << ", execution grade " << this->_requiredExecGrade
			  << " and target " << this->_target
			  << std::endl;
}

AForm::AForm(AForm const &src) : _name(src.getName() + "_copy"),
								 _requiredSignGrade(src.getRequiredSignGrade()),
								 _requiredExecGrade(src.getRequiredExecGrade()),
								 _target(src.getTarget())
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
	  << rhs.getRequiredSignGrade() << " to be signed";
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

int AForm::getRequiredSignGrade(void) const
{
	return this->_requiredSignGrade;
}

int AForm::getRequiredExecGrade(void) const
{
	return this->_requiredExecGrade;
}


std::string AForm::getTarget(void) const
{
	return this->_target;
}

void AForm::setSignedStatus(bool status)
{
	this->_signedStatus = status;
}


void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_requiredSignGrade && !this->_signedStatus)
	{
		this->_signedStatus = 1;
	}
	else if (!this->_signedStatus)
		throw AForm::GradeTooLowException();
	else
		throw AForm::AlreadySignedException();
}

void AForm::checkRequirements(Bureaucrat const &executor) const
{
	if (this->_signedStatus == 0)
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->_requiredExecGrade)
		throw AForm::GradeTooLowException();
}