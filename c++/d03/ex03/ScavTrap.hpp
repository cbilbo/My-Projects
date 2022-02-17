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

class ScavTrap: virtual public ClapTrap
{
public:
	ScavTrap(std::string const &name = _default_name, const int &hp = _default_hp, const int &ep = _default_ep, const int &dmg = _default_dmg);
	ScavTrap(ScavTrap const &copy);
	~ScavTrap();

	void	attack(std::string const &target);
	void	guardGate();
	
	static int			getDefHp(void);
	static int			getDefEp(void);
	static int			getDefDmg(void);
	
	ScavTrap &operator = (ScavTrap const &trap);
private:
	static std::string const	_default_name;
	static const int	_default_hp;
	static const int	_default_ep;
	static const int	_default_dmg;
};
