/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:27:30 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/08 16:27:31 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>

phonebook::phonebook()
{}

phonebook::~phonebook()
{}

void	phonebook::addContact(int idx)
{
	contact	cnt;
	std::string str;
	cnt.setIndex(idx);
	std::cout << "Firstname: ";
	std::getline(std::cin, str, '\n');
	checkeof();
	cnt.setFiname(str);
	std::cout << "Lastname: ";
	std::getline(std::cin, str, '\n');
	checkeof();
	cnt.setLaname(str);
	std::cout << "Nickname: ";
	std::getline(std::cin, str, '\n');
	checkeof();
	cnt.setNickname(str);
	std::cout << "Phone number: ";
	std::getline(std::cin, str, '\n');
	checkeof();
	cnt.setNumber(str);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, str, '\n');
	checkeof();
	cnt.setSecret(str);
	setContact(cnt);
}

void phonebook::setContact(contact cnt)
{
	_contacts[cnt.getIndex()].setIndex(cnt.getIndex());
	_contacts[cnt.getIndex()].setFiname(cnt.getFiname());
	_contacts[cnt.getIndex()].setLaname(cnt.getLaname());
	_contacts[cnt.getIndex()].setNickname(cnt.getNickname());
	_contacts[cnt.getIndex()].setNumber(cnt.getNumber());
	_contacts[cnt.getIndex()].setSecret(cnt.getSecret());
}

contact	phonebook::getContact(int idx)
{
	return (_contacts[idx]);
}

bool	phonebook::findContact(int idx)
{
	for (int i = 0; i < 8; ++i)
	{
		if ((_contacts[i].getIndex() == idx))
			return (true);
	}
	return (false); 
}

void	phonebook::showPhonebook(void)
{
	int	idx;
	std::string	inx;
	
	if (_contacts[0].getIndex() == -1)
		return ;
	printHeader(false);
	for (int i = 0; (_contacts[i].getIndex() != -1) && (i < 8); ++i)
		_contacts[i].showContact(false);
	while (true)
	{
		std::cout << "Enter index to show more info(or EXIT to return to main menu): ";
		std::getline(std::cin, inx, '\n');
		checkeof();
		if (inx.compare("EXIT") == 0)
			return ;
		if (inx.compare("") && std::isdigit(inx.at(0)))
		{
			idx = std::stoi(inx);
			if (findContact(idx))
			{
				printHeader(true);
				_contacts[idx].showContact(true);
				break ;
			}
		}
		std::cout << "Contact not found, try again!" << std::endl;
	}
		
}

void	checkeof(void)
{
	if (std::cin.eof())
		exit (0);
}