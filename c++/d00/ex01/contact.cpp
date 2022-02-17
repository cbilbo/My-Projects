/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:27:19 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/08 16:27:20 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include <string>
#include <iostream>
#include <iomanip>

contact::contact()
{
	_index = -1;
};

contact::~contact()
{};

void	contact::setIndex(int idx)
{
	_index = idx;
}

int	contact::getIndex(void)
{
	return (_index);
}

void	contact::setFiname(std::string finame)
{
	_finame = finame;
}

std::string	contact::getFiname(void)
{
	if ((_finame.length() > 10))
		return (_finame.substr(0, 9).append("."));
	return (_finame);
}

void	contact::setLaname(std::string laname)
{
	_laname = laname;
}

std::string	contact::getLaname(void)
{
	if ((_laname.length() > 10))
		return (_laname.substr(0, 9).append("."));
	return (_laname);
}

void	contact::setNickname(std::string nickname)
{
	_nickname = nickname;
}

std::string	contact::getNickname(void)
{
	if ((_nickname.length() > 10))
		return (_nickname.substr(0, 9).append("."));
	return (_nickname);
}

void	contact::setNumber(std::string number)
{
	_number = number;
}

std::string	contact::getNumber(void)
{
	if ((_number.length() > 10))
		return (_number.substr(0, 9).append("."));
	return(_number);
}

void	contact::setSecret(std::string secret)
{
	_secret = secret;
}

std::string	contact::getSecret(void)
{
	if ((_secret.length() > 10))
		return (_secret.substr(0, 9).append("."));
	return (_secret);
}

void	contact::showContact(bool s)
{
		std::cout << "|" << std::setw(10) << std::right << getIndex() << \
	"|" << std::setw(10) << std::right << getFiname() << \
	"|" << std::setw(10) << std::right << getLaname() << \
	"|" << std::setw(10) << std::right << getNickname() << "|";
	if (s)
	{
		std::cout << std::setw(10) << std::right << getNumber() << \
		"|" << std::setw(10) << std::right << getSecret() << "|";
	}
	std::cout << std::endl;
}

void printHeader(bool s)
{
	std::cout << "|" << std::setw(10) << std::right << "index" << \
	"|" << std::setw(10) << std::right << "firsname" << \
	"|" << std::setw(10) << std::right << "lastname" << \
	"|" << std::setw(10) << std::right << "nickname" << "|";
	if (s)
	{
		std::cout << std::setw(10) << std::right << "number" << \
		"|" << std::setw(10) << std::right << "secret" << "|";
	}
	std::cout << std::endl;
}