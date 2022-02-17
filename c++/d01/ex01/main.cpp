/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:14:42 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/09 20:17:10 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main(void)
{
	int	i;

	i = 10;
	Zombie *horde = ZombieHorde(i, "Semyon");
	horde->announce();
	std::cout << std::endl;
	for (int j = 0; j < i; ++j)
		horde[j].announce();
	delete[] horde;
	return (0);
}