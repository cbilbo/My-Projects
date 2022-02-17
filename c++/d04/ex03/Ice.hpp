/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:43:30 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/13 22:18:42 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <string>

class Ice: public AMateria
{
public:
	Ice(const std::string &name = "ice");
	Ice(const Ice &copy);
	virtual Ice &operator=(const Ice &copy);
	virtual ~Ice();
	virtual Ice *clone() const;
	virtual void use(ICharacter &target);
};