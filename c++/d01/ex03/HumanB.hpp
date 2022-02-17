/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:30:27 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/03 20:52:13 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Weapon.hpp"
#include <string>

class HumanB
{
private:
	std::string	_name;
	Weapon		*_wpn;
public:
	HumanB();
	HumanB(std::string name);
	~HumanB();
	void	attack();
	void	setWeapon(Weapon &weapon);
};
