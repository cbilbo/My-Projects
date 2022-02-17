/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:43:58 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/14 18:32:05 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "ICharacter.hpp"
# include <string>

class Character: public ICharacter
{
private:
	std::string _target;
	AMateria *_m[4];
public:
	Character(std::string const &target = "Default");
	Character(Character const &copy);
	virtual Character &operator=(Character const &copy);
	~Character();
	std::string const &GetName() const;
	void	equip(AMateria *m);
	void	unequip(int idx);
	void	use(int idx, ICharacter &target);
};