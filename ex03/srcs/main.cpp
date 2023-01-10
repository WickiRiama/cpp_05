/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:52:24 by mriant            #+#    #+#             */
/*   Updated: 2023/01/10 16:35:49 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "colors.h"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

Bureaucrat *instanciateBureaucrate(std::string name, int grade)
{
	Bureaucrat *newBureaucrat;
	try
	{
		newBureaucrat = new Bureaucrat(name, grade);
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << RED << e.what() << RES << std::endl;
		newBureaucrat = new Bureaucrat(name, 150);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << RED << e.what() << RES << std::endl;
		newBureaucrat = new Bureaucrat(name, 1);
	}
	return newBureaucrat;
}

int main(void)
{
	std::cout << BCYN << "Bureaucrats" << RES << std::endl;
	Bureaucrat *chief = instanciateBureaucrate("Chief", 1);
	Bureaucrat *maggot = instanciateBureaucrate("maggot", 150);
	Bureaucrat *bob = instanciateBureaucrate("Bob", 60);

	std::cout << std::endl
			  << BCYN << "Intern" << RES << std::endl;
	Intern intern;

	std::cout << std::endl
			  << BCYN << "Forms" << RES << std::endl;
	AForm *shrub = intern.makeForm("shrubbery", "target");
	AForm *robot = intern.makeForm("robotomy", "Mrs. Umbrage");
	AForm *pardon = intern.makeForm("pardon", "Alice");
	AForm *heeee = intern.makeForm("heeee?", "Can you repeat please ?");
	std::cout << "Address of heeee: " << heeee << std::endl;

	std::cout << std::endl
			  << BCYN << "Start status" << RES << std::endl;
	std::cout << "Chief: " << *chief << std::endl
			  << "Bob: " << *bob << std::endl
			  << "Maggot: " << *maggot << std::endl;

	std::cout << std::endl
			  << BCYN << "Promotions" << RES << std::endl;
	try
	{
		chief->promote();
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << RED << e.what() << RES << std::endl;
	}
	try
	{
		bob->promote();
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << RED << e.what() << RES << std::endl;
	}

	std::cout << std::endl
			  << BCYN << "Retrogradation" << RES << std::endl;
	try
	{
		bob->retrograde();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << RED << e.what() << RES << std::endl;
	}
	try
	{
		maggot->retrograde();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << RED << e.what() << RES << std::endl;
	}

	std::cout << std::endl
			  << BCYN << "End status" << RES << std::endl;
	std::cout << "Chief: " << *chief << std::endl
			  << "Bob: " << *bob << std::endl
			  << "Maggot: " << *maggot << std::endl;

	std::cout << std::endl
			  << BCYN << "Execute before signature" << RES << std::endl;
	maggot->executeForm(*shrub);
	bob->executeForm(*shrub);
	chief->executeForm(*shrub);
	maggot->executeForm(*robot);
	bob->executeForm(*robot);
	chief->executeForm(*robot);
	maggot->executeForm(*pardon);
	bob->executeForm(*pardon);
	chief->executeForm(*pardon);

	std::cout << std::endl
			  << BCYN << "Sign Forms" << RES << std::endl;
	maggot->signForm(*shrub);
	bob->signForm(*shrub);
	chief->signForm(*shrub);
	maggot->signForm(*robot);
	bob->signForm(*robot);
	chief->signForm(*robot);
	maggot->signForm(*pardon);
	bob->signForm(*pardon);
	chief->signForm(*pardon);

	std::cout << std::endl
			  << BCYN << "Execute after signature" << RES << std::endl;
	maggot->executeForm(*shrub);
	bob->executeForm(*shrub);
	chief->executeForm(*shrub);
	maggot->executeForm(*robot);
	bob->executeForm(*robot);
	for (int i = 0; i < 10; i++)
		chief->executeForm(*robot);
	maggot->executeForm(*pardon);
	bob->executeForm(*pardon);
	chief->executeForm(*pardon);

	std::cout << std::endl
			  << BCYN << "Destructors" << RES << std::endl;
	delete bob;
	delete chief;
	delete maggot;
	delete shrub;
	delete robot;
	delete pardon;
}