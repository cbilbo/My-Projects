/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:30:34 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/03 20:49:01 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Weapon.hpp"
#include <string>

class HumanA
{
private:
	std::string	_name;
	Weapon		&_wpn;
public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void	attack();
};
