/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 20:34:51 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/17 15:43:44 by cbilbo           ###   ########.fr       */
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
	Form(const std::string &name = "Default", 
		const int &sign_grade = 150, const int &exec_grade = 150, 
		const bool &is_signed = false);
	virtual ~Form() {}
	std::string	getName(void) const;
	virtual std::string getTarget(void) const = 0;
	int	getSignGrade(void) const;
	int getExecGrade(void) const;
	bool getIsSigned(void) const;
	void	beSigned(Bureaucrat &bur);
	virtual void execute(Bureaucrat const &executor) const = 0;
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
	const GradeTooHighException &getHigh(void) const;
	const GradeTooLowException &getLow(void) const;
private:
	const std::string _name;
	const int _sign_grade;
	const int _exec_grade;
	bool	_is_signed;
	const GradeTooHighException _high;
	const GradeTooLowException _low;
};

std::ostream	&operator<<(std::ostream &os, Form const &form);
