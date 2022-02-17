/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:30:56 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/17 16:45:22 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "Form.hpp"

class RobotomyRequestForm: public Form
{
public:
	RobotomyRequestForm(const std::string &target = "Earth", const int &sign_grade = 72, const int &exec_grade = 45, const bool &is_signed = false);
	~RobotomyRequestForm() {}
	std::string getTarget(void) const {return _target;}
	void execute(Bureaucrat const &executor) const;
private:
	std::string _target;
};