/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:27:26 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/10 19:26:03 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>

int main(void)
{
	phonebook	phonebook;
	std::string	cmd;
	int	i = 0;
	
	while (!std::cin.eof())
	{
		std::cout << "Please type command(ADD, SEARCH or EXIT): ";
		std::getline(std::cin, cmd, '\n');
		if (cmd.compare("ADD") == 0)
			phonebook.addContact(i++ % 8);
		else if (cmd.compare("SEARCH") == 0)
			phonebook.showPhonebook();
		else if (cmd.compare("EXIT") == 0)
		{
			std::cout << "Your phonebook was erased! Goodbye!" << std::endl;
			return (0);
		}
		else if (!std::cin.eof())
			std::cout << "Unknown command! Please try again!" << std::endl;
	}
	return (0);
}