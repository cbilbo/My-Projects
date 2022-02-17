/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:46:53 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/13 22:14:45 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"
#include <string>

class Cure: public AMateria
{
public:
    Cure(const std::string &name = "cure");
    Cure(const Cure &copy);
    virtual Cure    &operator=(const Cure &copy);
    virtual ~Cure();
    virtual Cure    *clone() const;
	virtual void use(ICharacter &target);
};
