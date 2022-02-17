/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:15:16 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/15 17:28:22 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>

class	ICharacter;

# include "ICharacter.hpp"

class AMateria
{
protected:
	std::string _type;
public:
    AMateria(std::string const &type = "Default");
	AMateria(const AMateria &copy);
	virtual ~AMateria() {}
	virtual AMateria &operator=(const AMateria &copy);
	std::string const &getType() const;
	virtual AMateria *clone() const = 0;
	virtual void	use(ICharacter &target);
};