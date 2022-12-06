/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:01:41 by mriant            #+#    #+#             */
/*   Updated: 2022/12/06 17:09:07 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//==============================================================================
// Constructors
//==============================================================================

Bureaucrat::Bureaucrat(void) : _name("unnamed_bureaucrat"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << "Bureaucrat constructor called with name " << this->_name
			  << " and grade " << grade << std::endl;
	if (grade >= 1 && grade <= 150)
		this->_grade = grade;
	else if (grade > 150)
		throw GradeTooLowException();
	else
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src.getName() + "_copy")
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = src;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

//==============================================================================
// Operators
//==============================================================================

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
		this->_grade = rhs.getGrade();
	return *this;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return o;
}

//==============================================================================
// Functions
//==============================================================================

std::string Bureaucrat::getName(void) const
{
	return this->_name;
}

int Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

void Bureaucrat::promote(void)
{
	if (this->_grade >= 2)
	{
		this->_grade--;
		std::cout << this->_name << " has been promoted to grade "
				  << this->_grade << std::endl;
	}
	else
		throw GradeTooHighException();
}

void Bureaucrat::retrograde(void)
{
	if (this->_grade <= 149)
	{
		this->_grade++;
		std::cout << this->_name << " has been retrograded to grade "
				  << this->_grade << std::endl;
	}
	else
		throw GradeTooLowException();
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch (const Form::GradeTooLowException &e)
	{
		std::cout << this->_name << " couldn't sign " << form.getName()
				  << " because his grade is too low" << std::endl;
	}
	catch (const Form::AlreadySignedException &e)
	{
		std::cout << this->_name << " couldn't sign " << form.getName()
				  << " because the form is already signed" << std::endl;
	}
}