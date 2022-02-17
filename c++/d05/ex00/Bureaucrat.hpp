/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:42:33 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/15 20:18:34 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>
# include <exception>
# include <ostream>
# include <iostream>

class Bureaucrat
{
public:
	Bureaucrat(const std::string &name = "Default", const int &grade = 150);
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat &operator=(const Bureaucrat &copy);
	~Bureaucrat() { std::cout << "Bureaucrat " << _name << " was fired\n"; }
	std::string	getName(void) const;
	int	getGrade(void) const;
	Bureaucrat operator++(int);
	Bureaucrat operator--(int);
	Bureaucrat &operator++();
	Bureaucrat &operator--();
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
	GradeTooHighException _high;
	GradeTooLowException _low;
	int _grade;
};

std::ostream	&operator<<(std::ostream &os, Bureaucrat const &bur);
