/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:18:05 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/14 13:50:05 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
# include <iostream>

class Zombie
{
private:
	std::string	_name;
public:
	Zombie();
	Zombie(std::string str);
	~Zombie();
	void	announce(void);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);
#endif