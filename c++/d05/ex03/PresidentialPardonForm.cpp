/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:30:50 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/17 16:45:41 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <string>
#include <fstream>
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string &target,
	const int &sign_grade, const int &exec_grade, const bool &is_signed) : Form("Presidential Pardon", sign_grade, exec_grade, is_signed), _target(target)
{}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() <= getExecGrade())
		std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox\n";
	else
		throw getLow();
}