/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:19:27 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/14 14:20:57 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class AMateria;

# include "AMateria.hpp"
# include <string>

class ICharacter
{
public:
    virtual ~ICharacter() {}
    virtual std::string const &GetName() const = 0;
    virtual void    equip(AMateria *m) = 0;
    virtual void    unequip(int idx) = 0;
    virtual void    use(int idx, ICharacter &target) = 0;
};