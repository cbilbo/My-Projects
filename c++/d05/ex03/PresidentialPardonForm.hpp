/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:30:52 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/17 16:45:53 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "Form.hpp"

class PresidentialPardonForm: public Form
{
public:
	PresidentialPardonForm(const std::string &target = "Earth", const int &sign_grade = 25, const int &exec_grade = 5, const bool &is_signed = false);
	~PresidentialPardonForm() {}
	std::string getTarget(void) const {return _target;}
	void execute(Bureaucrat const &executor) const;
private:
	std::string _target;
};