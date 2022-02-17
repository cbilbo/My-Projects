/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 22:41:49 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/28 17:15:00 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dynamic.hpp"

Base *generate(void)
{
	Base *res;
	srand(time(0));
	int i = rand() % 3;
	switch (i)
	{
	case 0:
		res = new A();
		std::cout << "Generate class A\n";
		break;
	case 1:
		res = new B;
		std::cout << "Generate class B\n";
		break;
	case 2:
		res = new C;
		std::cout << "Generate class C\n";
		break;
	}
	return (res);
}

void identify(Base* p)
{
	std::cout << "*:\n";
	if (dynamic_cast<A*>(p) != nullptr)
		std::cout << "A class inside Base*\n";
	else
		std::cout << "It is not A\n";
	if (dynamic_cast<B*>(p) != nullptr)
		std::cout << "B class inside Base*\n";
	else
		std::cout << "It is not B\n";
	if (dynamic_cast<C*>(p) != nullptr)
		std::cout << "C class inside Base*\n";
	else
		std::cout << "It is not C\n";
}

void identify(Base& p)
{
	Base *temp;
	std::cout << "&:\n";
	try
	{
		temp = &dynamic_cast<A&>(p);
		std::cout << "A class inside Base\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "It is not A\n";
	}
	try
	{
		temp = &dynamic_cast<B&>(p);
		std::cout << "B class inside Base\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "It is not B\n";
	}
	try
	{
		temp = &dynamic_cast<C&>(p);
		std::cout << "C class inside Base\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "It is not C\n";
	}
}