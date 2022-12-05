/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:52:24 by mriant            #+#    #+#             */
/*   Updated: 2022/12/05 14:57:49 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "colors.h"

int main(void)
{
	std::cout << BCYN << "Constructors" << RES << std::endl;
	Bureaucrat unnamed;
	Bureaucrat bob("Bob", 20);
	Bureaucrat bob_cpy(bob);

	std::cout << BCYN << "Destructors" << RES << std:: endl;
}