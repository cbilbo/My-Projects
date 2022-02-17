/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 20:34:59 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/17 15:43:39 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string &name, const int &sign_grade, const int &exec_grade, const bool &is_signed)\
	: _name(name), _sign_grade(sign_grade), _exec_grade(exec_grade), _is_signed(is_signed)
{
	if (_sign_grade < 1 || _exec_grade < 1)
		throw _high;
	if (_sign_grade > 150 || _exec_grade > 150)
		throw _low;
}

std::string Form::getName(void) const {return _name;}
int	Form::getSignGrade(void) const {return _sign_grade;}
int	Form::getExecGrade(void) const {return _exec_grade;}
bool Form::getIsSigned(void) const {return _is_signed;}

void	Form::beSigned(Bureaucrat &bur)
{
	if (bur.getGrade() <= _sign_grade)
		_is_signed = true;
	else
		throw _low;
}


std::ostream	&operator<<(std::ostream &os, Form const &form)
{
	os << form.getName() << ", min signed grade is " << form.getSignGrade() << ", min execute grade is " << form.getExecGrade() << (form.getIsSigned() ? ", form signed" : ", form unsigned");
	return (os);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

const Form::GradeTooHighException &Form::getHigh(void) const
{
	return (_high);
}

const Form::GradeTooLowException &Form::getLow(void) const
{
	return (_low);
}