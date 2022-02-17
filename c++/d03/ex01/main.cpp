/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:59:01 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/10 17:57:01 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <string>
#include <iostream>

int main(void)
{
	{
		ClapTrap	trap("Flower");
		for (int i = 15; i != 0; --i)
			trap.attack("Wanderer");
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
		for (int i = 55; i != 0; --i)
			trap.attack("Wanderer");
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
	return (0);
}