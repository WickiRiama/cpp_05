/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:52:24 by mriant            #+#    #+#             */
/*   Updated: 2022/12/06 17:24:13 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "colors.h"

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

Form *instanciateForm(std::string name, int requiredGrade)
{
	Form *newForm;
	try
	{
		newForm = new Form(name, requiredGrade);
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << RED << e.what() << RES << std::endl;
		newForm = new Form(name, 150);
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << RED << e.what() << RES << std::endl;
		newForm = new Form(name, 1);
	}
	return newForm;
}

int main(void)
{
	std::cout << BCYN << "Bureaucrats" << RES << std::endl;
	Bureaucrat *chief = instanciateBureaucrate("Chief", 1);
	Bureaucrat *maggot = instanciateBureaucrate("maggot", 150);
	Bureaucrat *bob = instanciateBureaucrate("Bob", 60);

	std::cout << std::endl
			  << BCYN << "Forms" << RES << std::endl;
	Form unnamedForm;
	Form *A80 = instanciateForm("A80", 80);
	Form A80_cpy = Form(*A80);
	Form *A150 = instanciateForm("A150", 150);
	Form *A1 = instanciateForm("A1", 1);

	std::cout << std::endl
			  << BCYN << "Start status" << RES << std::endl;
	std::cout << "Chief: " << *chief << std::endl
			  << "Bob: " << *bob << std::endl
			  << "Maggot: " << *maggot << std::endl;
	std::cout << "Default form: " << unnamedForm << std::endl
			  << "A80: " << *A80 << std::endl
			  << "Copy: " << A80_cpy << std::endl
			  << "A1: " << *A1 << std::endl
			  << "A150: " << *A150 << std::endl;

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
			  << BCYN << "Sign Forms" << RES << std::endl;
	maggot->signForm(*A1);
	maggot->signForm(*A80);
	maggot->signForm(*A150);
	bob->signForm(*A1);
	bob->signForm(*A80);
	bob->signForm(*A150);
	chief->signForm(*A1);
	chief->signForm(*A80);
	chief->signForm(*A150);

	std::cout << std::endl
			  << BCYN << "End status" << RES << std::endl;
	std::cout << "Chief: " << *chief << std::endl
			  << "Bob: " << *bob << std::endl
			  << "Maggot: " << *maggot << std::endl;
	std::cout << "Default form: " << unnamedForm << std::endl
			  << "A80: " << *A80 << std::endl
			  << "Copy: " << A80_cpy << std::endl
			  << "A1: " << *A1 << std::endl
			  << "A150: " << *A150 << std::endl;

	std::cout << std::endl
			  << BCYN << "Destructors" << RES << std::endl;
	delete bob;
	delete chief;
	delete maggot;
	delete A1;
	delete A80;
	delete A150;
}