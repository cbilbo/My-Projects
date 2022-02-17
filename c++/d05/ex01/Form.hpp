/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 20:34:51 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/15 21:43:35 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "Bureaucrat.hpp"
# include <string>
# include <exception>
# include <ostream>
# include <iostream>

class Bureaucrat;

class Form
{
public:
	Form(const std::string &name = "Default", const int &sign_grade = 150, const int &exec_grade = 1, const bool &is_signed = false);
	Form(const Form &copy);
	Form &operator=(const Form &copy);
	~Form() {}
	std::string	getName(void) const;
	int	getSignGrade(void) const;
	int getExecGrade(void) const;
	bool getIsSigned(void) const;
	void	beSigned(const Bureaucrat &bur);
	class GradeTooHighException: public std::exception
	{
	public:
		GradeTooHighException() {}
		~GradeTooHighException() throw() {}
		const char* what() const throw();
	};
	class GradeTooLowException: public std::exception
	{
	public:
		GradeTooLowException() {}
		~GradeTooLowException() throw() {}
		const char* what() const throw();
	};	
private:
	const std::string _name;
	const int _sign_grade;
	const int _exec_grade;
	bool	_is_signed;
	GradeTooHighException _high;
	GradeTooLowException _low;
};

std::ostream	&operator<<(std::ostream &os, Form const &form);
