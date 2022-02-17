/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:41:58 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/15 21:49:35 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
	std::cout << "\n===================\n";
	try
	{
		Form	q("doc-1", 234, 5);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	
	std::cout << "\n===================\n";
	try
	{
		Form e("doc0", -4, 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	
	std::cout << "\n===================\n";
	Form f("doc", 5, 5);
	Bureaucrat	m("Mark", 2);
	try
	{
		f.beSigned(m);
		Form a("doc1", 1, 1);
		a.beSigned(m);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	
	std::cout << "\n===================\n";
	return (0);
}