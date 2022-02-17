/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:25:10 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/13 16:35:41 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <string>
#include <iostream>

Cat::Cat(const std::string &name) : Animal(name)
{
	std::cout << "Cat " << _type << " created." << std::endl;
}
Cat::Cat(const Cat &copy) : Animal(copy._type)
{
	std::cout << "Cat " << _type << "was copied by " << copy._type  << '.' << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat " << _type << " deleted." << std::endl;
}

Cat	&Cat::operator=(Cat const &src)
{
	if (this == &src)
		return (*this);
	this->_type = src._type;
	return (*this);
}
void	Cat::makeSound(void) const
{
	std::cout << _type << " says : Meow!" << std::endl;
}