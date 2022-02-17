/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:42:20 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/16 22:22:03 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, const int &grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw _high;
	else if (grade > 150)
		throw _low;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{
}

std::string Bureaucrat::getName(void) const
{
	return (_name);
}

int Bureaucrat::getGrade(void) const
{
	return (_grade);
}

Bureaucrat Bureaucrat::operator++(int)
{
	if (_grade == 1)
		throw _high;
	Bureaucrat	temp(*this);
	--_grade;
	return (temp);
}

Bureaucrat Bureaucrat::operator--(int)
{
	if (_grade == 150)
		throw _low;
	Bureaucrat temp(*this);
	++_grade;
	return (temp);
}

Bureaucrat	&Bureaucrat::operator++()
{
	if (_grade == 1)
		throw _high;
	--_grade;
	return (*this);
}

Bureaucrat &Bureaucrat::operator--()
{
	if (_grade == 150)
		throw _low;
	++_grade;
	return (*this);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

void	Bureaucrat::signForm(Form &form)
{
	if (!form.getIsSigned())
	{
		try
		{
			form.beSigned(*this);
			std::cout << this->getName() << " signed " << form.getName() << '\n';
		}
		catch(const std::exception& e)
		{
			std::cerr << this->getName() << " can't signed " << form.getName() << " due to bureaucrat's " << e.what() << "\n";
		}
	}
	else
		std::cout << this->getName() << " can't signed " << form.getName() << " due to form is already signed!" << std::endl;
}

void Bureaucrat::executeForm(Form const &form) const
{
	if (form.getIsSigned())
	{
		try
		{
			form.execute(*this);
			std::cout << this->getName() << " execute " << form.getName() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << this->getName() << " can't execute " << form.getName() << " due to bureaucrat's " <<  e.what() << '\n';
		}
	}	
	else
		std::cout << this->getName() << " can't execute " << form.getName() << " due to form isn't signed!" << std::endl;
}

std::ostream	&operator<<(std::ostream& os, Bureaucrat const &bur)
{
	os << bur.getName() << ", bureaucrat grade " << bur.getGrade();
	return (os);
}