/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:27:37 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/08 16:27:38 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

int main(int ac, char **av)
{
	if (ac < 2)
		std::cout << "Loud void";
	else
	{
		std::string str;
		for (int i = 1; i < ac; i++)
		{
			if (i != 1)
				std::cout << " ";
			str = av[i];
			std::transform(str.begin(), str.end(), str.begin(), ::toupper);
			std::cout << str;
		}
	}
	std::cout << std::endl;
	return 0;
}