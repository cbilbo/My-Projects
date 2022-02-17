/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:53:26 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/13 20:21:41 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <string>
#include <iostream>

Brain::Brain(const std::string &owner) : _owner(owner)
{
	std::cout << owner << " brain was created!\n";
}

Brain::Brain(const Brain &copy)
{
	for (int i = 0; i < 100; ++i)
		_ideas[i] = copy._ideas[i];
	_owner = copy._owner;
	std::cout << _owner << " brain was copied!\n";
}
Brain	&Brain::operator=(const Brain &brain)
{
	if (this == &brain)
		return (*this);
	for (int i = 0; i < 100; ++i)
		_ideas[i] = brain._ideas[i];
	_owner = brain._owner;
	std::cout << _owner << " brain was assigned\n";
	return (*this);
}

Brain::~Brain()
{
	std::cout << _owner << " brain was deleted\n";
}

void	Brain::setIdea(const std::string &idea, int pos)
{
	if (pos > 100 || pos < 1)
		std::cout << "Sorry, " << _owner << " is stupid\n";
	else
	{
		_ideas[pos - 1] = idea;
		std::cout << _owner << " have a new idea\n";
	}
}

std::string Brain::getIdea(int pos) const
{
	if (pos > 100 || pos < 1)
	{
		std::cout << "Sorry, " << _owner << " don't know that\n";
		return ("I'm so stupid");
	}
	else
	{
		return (_ideas[pos - 1]);
	}
}