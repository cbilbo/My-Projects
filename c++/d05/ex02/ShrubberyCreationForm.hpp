/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:29:55 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/17 16:44:37 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "Form.hpp"

class ShrubberyCreationForm: public Form
{
public:
	ShrubberyCreationForm(const std::string &target = "Earth", const int &sign_grade = 145, const int &exec_grade = 137, const bool &is_signed = false);
	std::string	getTarget(void) const {return (_target); }
	~ShrubberyCreationForm() {}
	void execute(Bureaucrat const &executor) const;
private:
	const std::string _target; 
};