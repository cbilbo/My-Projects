/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:59:50 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/13 16:02:30 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>
# include <iostream>

class ClapTrap
{
public:
	ClapTrap(std::string const &name = _default_name, const int &hp = _default_hp, const int &ep = _default_ep, const int &dmg = _default_dmg);
	ClapTrap(ClapTrap const &copy);
	~ClapTrap();
	
	std::string	getName(void) const;
	void		setName(std::string const &name);
	int			getHp(void) const;
	void		setHp(const int &hp);	
	int			getEp(void) const;
	void		setEp(const int &ep);
	int			getDmg(void) const;
	void		setDmg(const int &dmg);
	static int	getDefHp(void);
	static int	getDefEp(void);
	static int	getDefDmg(void);
	
	void		attack(std::string const &target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	
	ClapTrap &operator = (ClapTrap const &trap);

protected:
	std::string	_name;
	int	_hp;
	int	_ep;
	int	_dmg;

private:
	static std::string const	_default_name;
	static const int	_default_hp;
	static const int	_default_ep;
	static const int	_default_dmg;
};
