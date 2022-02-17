/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:59:01 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/10 17:54:33 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <string>

int main(void)
{
	ClapTrap	trap("Flower");
	for (int i = 55; i != 0; --i)
		trap.attack("Wanderer");
	ClapTrap	trap2("Bug");
	trap2.attack("bee");
	trap2.takeDamage(100);
	trap2.attack("bee");
	trap2.beRepaired(4);
	trap2.attack("bee");
	trap2.takeDamage(2);
	return (0);
}