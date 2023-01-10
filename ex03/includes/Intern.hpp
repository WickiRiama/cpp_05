/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:50:00 by mriant            #+#    #+#             */
/*   Updated: 2023/01/10 15:37:29 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

#include "AForm.hpp"

class Intern
{
	private:
		AForm *makeShrubberyCreationForm(std::string target) const;
		AForm *makeRobotomyRequestForm(std::string target) const;
		AForm *makePresidentialPardonForm(std::string target) const;

	public:
		Intern(void);
		Intern(Intern const &src);
		~Intern(void);

		Intern &operator=(Intern const &rhs);
		
		AForm *makeForm(std::string name, std::string target);
};

typedef AForm *(Intern::*makeFunction)(std::string) const;


#endif