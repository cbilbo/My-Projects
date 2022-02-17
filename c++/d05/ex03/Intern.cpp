/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:14:28 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/17 16:47:50 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Form *Intern::makeForm(const std::string name, const std::string target)
{
	Form *ret;
	int	form = 0;
	std::string type[3] = \
		{"Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};
	for (int i = 0; i < 3; ++i)
	{
		switch (name.compare(type[i]))
		{
		case 0:
			form = i + 1;
			break ;
		default:
			continue ;
		}
	}
	switch (form)
	{
	case 1:
		ret = new ShrubberyCreationForm(target);
		break ;
	case 2:
		ret = new RobotomyRequestForm(target);
		break ;
	case 3:
		ret = new PresidentialPardonForm(target);
		break ;
	default:
		std::cout << "Intern doesn't know \"" << name << "\" type of form!\n";
		return (0);
	}
	std::cout << "Intern create " << ret->getName() << " form\n";
	return (ret);
}