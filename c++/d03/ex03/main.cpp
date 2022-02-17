/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:59:01 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/13 16:00:52 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <string>
#include <iostream>

int main(void)
{
	{
		DiamondTrap	trap("Flower");
		std::cout << "\n==============================\n\n";
		trap.printInfo();
		std::cout << "\n==============================\n\n";
		for (int i = 0; i < 55; ++i)
			trap.attack("Wanderer " + std::to_string(i + 1));
		std::cout << "\n==============================\n\n";
	}
	std::cout << "\n==============================\n\n";
	{
		DiamondTrap	trap2("Bug");
		std::cout << "\n==============================\n\n";
		trap2.attack("bee");
		std::cout << "\n==============================\n\n";
		trap2.takeDamage(10);
		std::cout << "\n==============================\n\n";
		trap2.takeDamage(500);
		std::cout << "\n==============================\n\n";
		trap2.attack("bee");
		std::cout << "\n==============================\n\n";
		trap2.beRepaired(4);
		std::cout << "\n==============================\n\n";
		trap2.attack("bee");
		std::cout << "\n==============================\n\n";
		trap2.takeDamage(2);
		std::cout << "\n==============================\n\n";
		trap2.guardGate();
		std::cout << "\n==============================\n\n";
		trap2.highFivesGuys();
		std::cout << "\n==============================\n\n";
		trap2.WhoAmI();
		std::cout << "\n==============================\n\n";
	}
	return (0);
}