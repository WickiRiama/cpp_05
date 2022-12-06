/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:28:07 by mriant            #+#    #+#             */
/*   Updated: 2022/12/06 17:36:00 by mriant           ###   ########.fr       */
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
	int const _requiredGrade;

public:
	AForm(void);
	AForm(std::string name, int requiredGrade);
	AForm(AForm const &src);
	~AForm(void);

	AForm &operator=(AForm const &rhs);

	std::string getName(void) const;
	bool getSignedStatus(void) const;
	int getRequiredGrade(void) const;
	void beSigned(Bureaucrat &bureaucrat);
	void execute(Bureaucrat const &executor);

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

std::ostream &operator<<(std::ostream &o, AForm const &rhs);

#endif