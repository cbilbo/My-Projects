/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:30:24 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/03 20:40:00 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Weapon
{
private:
	std::string _type;
public:
	Weapon();
	Weapon(std::string type);
	~Weapon();
	std::string const &getType(void);
	void	setType(std::string wpn);
};
