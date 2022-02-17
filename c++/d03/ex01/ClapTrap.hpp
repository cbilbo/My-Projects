/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:59:50 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/10 17:38:47 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>

class ClapTrap
{
public:
	ClapTrap();
	ClapTrap(std::string const &name);
	ClapTrap(ClapTrap const &copy);
	ClapTrap(std::string const &name, const int &hp, const int &ep, const int &dmg);
	~ClapTrap();
	
	std::string	getName(void) const;
	void		setName(std::string const &name);
	int			getHp(void) const;
	void		setHp(const int &hp);	
	int			getEp(void) const;
	void		setEp(const int &ep);
	int			getDmg(void) const;
	void		setDmg(const int &dmg);

	void	attack(std::string const &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	
	ClapTrap &operator = (ClapTrap const &trap);

protected:
	std::string	_name;
	int	_hp;
	int	_ep;
	int _dmg;
};
