/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:41:58 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/17 16:46:30 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

int main(void)
{
	Bureaucrat a("a150", 150);
	Bureaucrat a1("a1-140", 140);
	Bureaucrat b("b70", 70);
	Bureaucrat b1("b1-20", 20);
	Bureaucrat c("c2", 2);
	Form *f[3];
	f[0] = new ShrubberyCreationForm("World"); 
	f[1] = new RobotomyRequestForm("Code");
	f[2] = new PresidentialPardonForm("Earth");
	std::cout << "===================\n";
	a.signForm(*f[0]);
	a.executeForm(*f[0]);
	std::cout << "===================\n";
	a1.signForm(*f[0]);
	a1.executeForm(*f[0]);
	std::cout << "===================\n";
	b.signForm(*f[0]);
	b.executeForm(*f[0]);
	std::cout << "===================\n";
	a.signForm(*f[1]);
	b.signForm(*f[1]);
	b.executeForm(*f[1]);
	std::cout << "===================\n";
	b1.signForm(*f[1]);
	b1.executeForm(*f[1]);
	std::cout << "===================\n";
	b1.signForm(*f[2]);
	b1.executeForm(*f[2]);
	std::cout << "===================\n";
	c.signForm(*f[2]);
	c.executeForm(*f[2]);
	std::cout << "===================\n";
	delete f[0];
	delete f[1];
	delete f[2];
	return (0);
}