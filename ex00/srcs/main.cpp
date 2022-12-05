/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:52:24 by mriant            #+#    #+#             */
/*   Updated: 2022/12/05 17:32:31 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "colors.h"

Bureaucrat *instanciateBureaucrate(std::string name, int grade)
{
	Bureaucrat *newBureaucrat;
	try
	{
		newBureaucrat = new Bureaucrat(name, grade);
	}
	catch (Bureaucrat::GradeTooLowException e)
	{
		std::cout << RED << e.what() << RES << std::endl;
		newBureaucrat = new Bureaucrat(name, 150);
	}
	catch (Bureaucrat::GradeTooHighException e)
	{
		std::cout << RED << e.what() << RES << std::endl;
		newBureaucrat = new Bureaucrat(name, 1);
	}
	return newBureaucrat;
}

int main(void)
{
	std::cout << BCYN << "Constructors" << RES << std::endl;
	Bureaucrat unnamed;
	Bureaucrat *bob = instanciateBureaucrate("Bob", 166);;
	Bureaucrat bob_cpy = Bureaucrat(*bob);

	std::cout << std::endl
			  << BCYN << "Start status" << RES << std::endl;
	std::cout << "Default: " << unnamed << std::endl
			  << "Bob: " << *bob << std::endl
			  << "Copy: " << bob_cpy << std::endl;

	std::cout << std::endl
			  << BCYN << "Promotions" << RES << std::endl;
	try
	{
		unnamed.retrograde();
	}
	catch (Bureaucrat::GradeTooLowException e)
	{
		std::cout << RED << e.what() << RES << std::endl;
	}
	try
	{
		bob->retrograde();
	}
	catch (Bureaucrat::GradeTooLowException e)
	{
		std::cout << RED << e.what() << RES << std::endl;
	}
	try
	{
		bob_cpy.promote();
	}
	catch (Bureaucrat::GradeTooHighException e)
	{
		std::cout << RED << e.what() << RES << std::endl;
	}

	std::cout << std::endl
			  << BCYN << "End status" << RES << std::endl;
	std::cout << "Default: " << unnamed << std::endl
			  << "Bob: " << *bob << std::endl
			  << "Copy: " << bob_cpy << std::endl;

	std::cout << std::endl
			  << BCYN << "Destructors" << RES << std::endl;
	delete bob;
}