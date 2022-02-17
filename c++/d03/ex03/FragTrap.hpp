/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:21:30 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/13 15:57:20 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "ClapTrap.hpp"
# include <string>

class FragTrap: virtual public ClapTrap
{
private:
public:
	FragTrap(std::string const &name = _default_name, const int &hp = _default_hp, const int &ep = _default_ep, const int &dmg = _default_dmg);
	FragTrap(FragTrap const &copy);
	~FragTrap();
	
	void	attack(std::string const &target);
	void	highFivesGuys(void);
	
	static int			getDefHp(void);
	static int			getDefEp(void);
	static int			getDefDmg(void);

	FragTrap &operator = (FragTrap const &trap);
private:
	static std::string const	_default_name;
	static const int	_default_hp;
	static const int	_default_ep;
	static const int	_default_dmg;	
};
