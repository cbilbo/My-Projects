/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:14:42 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/09 20:11:32 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie	*zombie;

	zombie = newZombie("Karl");
	zombie->announce();
	randomChump("Steve");
	delete zombie;
	return (0);
}