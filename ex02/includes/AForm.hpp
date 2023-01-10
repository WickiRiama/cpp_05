/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:28:07 by mriant            #+#    #+#             */
/*   Updated: 2023/01/10 11:25:18 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	std::string const _name;
	bool _signedStatus;
	int const _requiredSignGrade;
	int const _requiredExecGrade;
	std::string const _target;

public:
	AForm(void);
	AForm(std::string name, int signGrade, int execGrade, std::string target);
	AForm(AForm const &src);
	virtual ~AForm(void);

	AForm &operator=(AForm const &rhs);

	std::string getName(void) const;
	bool getSignedStatus(void) const;
	int getRequiredSignGrade(void) const;
	int getRequiredExecGrade(void) const;
	std::string getTarget(void) const;
	
	void beSigned(Bureaucrat &bureaucrat);
	void checkRequirements(Bureaucrat const &executor) const;
	virtual void execute(Bureaucrat const &executor) const = 0;

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "The grade is too high, it doesn't exist";
		}
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "The grade is too low, you can not do this action";
		}
	};
	class AlreadySignedException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "The form is already signed";
		}
	};
	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "The file is not signed";
		}
	};

};

std::ostream &operator<<(std::ostream &o, AForm const &rhs);

#endif