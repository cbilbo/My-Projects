/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:01:49 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/13 16:01:50 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
public:
	DiamondTrap(std::string const &name = _default_name, const int &hp = _default_hp, const int &ep = _default_ep, const int &dmg = _default_dmg);
	DiamondTrap(DiamondTrap const &copy);
	~DiamondTrap();
	void	attack(std::string const &target);
	void WhoAmI();
	void		setEp(const int &ep);
	int			getDmg(void) const;
	void		setDmg(const int &dmg);
	std::string	getName(void) const;
	static int			getDefHp(void);
	static int			getDefEp(void);
	static int			getDefDmg(void);
	void			printInfo(void) const;
	
	DiamondTrap &operator = (DiamondTrap const &trap);
private:
	std::string _name;
	static std::string const	_default_name;
	static const int	_default_hp;
	static const int	_default_ep;
	static const int	_default_dmg;
};