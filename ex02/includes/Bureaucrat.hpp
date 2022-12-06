/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:50:28 by mriant            #+#    #+#             */
/*   Updated: 2022/12/06 12:43:30 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	std::string const _name;
	int _grade;

public:
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "This bureaucrat is already the best, he can't be promoted";
		}
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "This bureaucrat has already reached the bottom, you can't harm him anymore";
		}
	};

	Bureaucrat(void);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const &src);
	~Bureaucrat(void);

	Bureaucrat &operator=(Bureaucrat const &rhs);

	std::string getName(void) const;
	int getGrade(void) const;
	void promote(void);
	void retrograde(void);
	void signForm(Form &form);
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif
