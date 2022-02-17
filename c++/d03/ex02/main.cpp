/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:59:01 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/10 21:23:02 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>
#include <iostream>

int main(void)
{
	{
		ClapTrap	trap("Flower");
		for (int i = 0; i < 15; ++i)
			trap.attack("Wanderer " + std::to_string(i + 1));
		ClapTrap	trap2("Bug");
		trap2.attack("bee");
		trap2.takeDamage(100);
		trap2.attack("bee");
		trap2.beRepaired(4);
		trap2.attack("bee");
		trap2.takeDamage(2);
	}
	std::cout << "\n===========================================================================\n\n";
	{
		ScavTrap	trap("Flower");
		for (int i = 0; i < 55; ++i)
			trap.attack("Wanderer " + std::to_string(i + 1));
		ScavTrap	trap2("Bug");
		trap2.attack("bee");
		trap2.takeDamage(10);
		trap2.takeDamage(500);
		trap2.attack("bee");
		trap2.beRepaired(4);
		trap2.attack("bee");
		trap2.takeDamage(2);
		trap2.guardGate();
	}
	std::cout << "\n===========================================================================\n\n";
	{
		FragTrap	trap("Flower");
		for (int i = 0; i < 105; ++i)
			trap.attack("Wanderer " + std::to_string(i + 1));
		FragTrap	trap2("Bug");
		trap2.attack("bee");
		trap2.takeDamage(10);
		trap2.takeDamage(500);
		trap2.attack("bee");
		trap2.beRepaired(4);
		trap2.attack("bee");
		trap2.takeDamage(2);
		trap2.highFivesGuys();
	}
	return (0);
}