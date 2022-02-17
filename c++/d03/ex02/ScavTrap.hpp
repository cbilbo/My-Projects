/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:27:01 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/10 18:23:07 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "ClapTrap.hpp"
# include <string>

class ScavTrap: public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string const &name);
	ScavTrap(ScavTrap const &copy);
	~ScavTrap();

	void	attack(std::string const &target);
	void	guardGate();
	
	ScavTrap &operator = (ScavTrap const &trap);
};
