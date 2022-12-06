/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 09:43:45 by mriant            #+#    #+#             */
/*   Updated: 2022/12/06 17:07:14 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	std::string const _name;
	bool _signedStatus;
	int const _requiredGrade;

public:
	Form(void);
	Form(std::string name, int requiredGrade);
	Form(Form const &src);
	~Form(void);

	Form &operator=(Form const &rhs);

	std::string getName(void) const;
	bool getSignedStatus(void) const;
	int getRequiredGrade(void) const;
	void beSigned(Bureaucrat &bureaucrat);

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
			return "The is already signed";
		}
	};
};

std::ostream &operator<<(std::ostream &o, Form const &rhs);

#endif