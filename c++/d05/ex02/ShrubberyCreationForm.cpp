/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:29:59 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/17 16:44:15 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <string>
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target,\
	const int &sign_grade, const int &exec_grade, const bool &is_signed) : Form("Shrubbery Creation", sign_grade, exec_grade, is_signed), _target(target)
{}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() <= getExecGrade())
	{
		std::ofstream	out(getTarget() + "_shrubbery");
		out << 
"             /\\" << std::endl <<
"            <  >" << std::endl <<
"             \\/" << std::endl <<
"             /\\" << std::endl <<
"            /  \\" << std::endl <<
"           /++++\\" << std::endl <<
"          /  ()  \\" << std::endl <<
"          /      \\" << std::endl <<
"         /~`~`~`~`\\" << std::endl <<
"        /  ()  ()  \\" << std::endl <<
"        /          \\" << std::endl <<
"       /*&*&*&*&*&*&\\" << std::endl <<
"      /  ()  ()  ()  \\" << std::endl <<
"      /              \\" << std::endl <<
"     /++++++++++++++++\\" << std::endl <<
"    /  ()  ()  ()  ()  \\" << std::endl <<
"    /                  \\" << std::endl <<
"   /~`~`~`~`~`~`~`~`~`~`\\" << std::endl <<
"  /  ()  ()  ()  ()  ()  \\" << std::endl <<
"  /*&*&*&*&*&*&*&*&*&*&*&\\" << std::endl <<
" /                        \\" << std::endl <<
"/,.,.,.,.,.,.,.,.,.,.,.,.,.\\" << std::endl <<
"           |   |" << std::endl <<
"          |`````|" << std::endl <<
"          \\_____/" << std::endl;
		out.close();
	}
	else
		throw getLow();
	
}