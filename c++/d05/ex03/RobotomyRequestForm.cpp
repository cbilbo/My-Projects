/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:30:54 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/17 16:45:09 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <unistd.h>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target,\
	const int &sign_grade, const int &exec_grade, const bool &is_signed) : Form("Robotomy Request", sign_grade, exec_grade, is_signed), _target(target)
{}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	std::cout << '\a' << "*bzzzzz*\n";
	std::cout << '\a' << "*bzzzzz*\n";
	if (executor.getGrade() <= getExecGrade())
	{
		std::cout << getTarget() << " has been robotomized successfully 50\% of the time.\n"; 
	}
	else
	{
		std::cout << "Failure!!!\n";
		throw getLow();
	}
}