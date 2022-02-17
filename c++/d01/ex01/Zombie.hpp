/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:18:05 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/03 19:13:53 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Zombie
{
private:
	std::string	_name;
public:
	Zombie(void);
	Zombie(std::string str);
	void setName(std::string str);
	~Zombie(void);
	void	announce(void);
};

Zombie* ZombieHorde(int N, std::string name);