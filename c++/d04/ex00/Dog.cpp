/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:22:21 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/13 16:35:43 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <string>
#include <iostream>

Dog::Dog(const std::string &name) : Animal(name)
{
	std::cout << "Dog " << _type << " created." << std::endl;
}
Dog::Dog(const Dog &copy) : Animal(copy._type)
{
	std::cout << "Dog " << _type << "was copied by " << copy._type  << '.' << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog " << _type << " deleted." << std::endl;
}

Dog	&Dog::operator=(Dog const &src)
{
	if (this == &src)
		return (*this);
	this->_type = src._type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << _type << " says : Wuff!" << std::endl;
}