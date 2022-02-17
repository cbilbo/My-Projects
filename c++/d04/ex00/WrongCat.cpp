/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:38:32 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/13 16:46:19 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <string>
#include <iostream>

WrongCat::WrongCat(const std::string &name) : WrongAnimal(name)
{
	std::cout << "WrongCat " << _type << " created." << std::endl;
}
WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy._type)
{
	std::cout << "WrongCat " << _type << "was copied by " << copy._type  << '.' << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat " << _type << " deleted." << std::endl;
}

WrongCat	&WrongCat::operator=(WrongCat const &src)
{
	if (this == &src)
		return (*this);
	this->_type = src._type;
	return (*this);
}
void	WrongCat::makeSound(void) const
{
	std::cout << _type << " says : Meow!" << std::endl;
}