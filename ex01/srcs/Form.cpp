/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 09:59:47 by mriant            #+#    #+#             */
/*   Updated: 2022/12/06 17:08:32 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

//==============================================================================
// Constructors
//==============================================================================

Form::Form(void) : _name("unnamed_form"), _signedStatus(0), _requiredGrade(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, int requiredGrade) : _name(name), _signedStatus(0),
												  _requiredGrade(requiredGrade)
{
	if (requiredGrade > 150)
		throw Form::GradeTooLowException();
	else if (requiredGrade < 1)
		throw Form::GradeTooHighException();
	std::cout << "Form constructor called with name " << this->_name
			  << " and required grade " << this->_requiredGrade << std::endl;
}

Form::Form(Form const &src) : _name(src.getName() + "_copy"),
							  _requiredGrade(src.getRequiredGrade())
{
	*this = src;
	std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form(void)
{
	std::cout << "Form destructor called" << std::endl;
}

//==============================================================================
// Operators
//==============================================================================

Form &Form::operator=(Form const &rhs)
{
	if (this != &rhs)
	{
		this->_signedStatus = rhs.getSignedStatus();
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, Form const &rhs)
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

std::string Form::getName(void) const
{
	return this->_name;
}

bool Form::getSignedStatus(void) const
{
	return this->_signedStatus;
}

int Form::getRequiredGrade(void) const
{
	return this->_requiredGrade;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_requiredGrade && !this->_signedStatus)
	{
		this->_signedStatus = 1;
	}
	else if (!this->_signedStatus)
		throw Form::GradeTooLowException();
	else
		throw Form::AlreadySignedException();
}