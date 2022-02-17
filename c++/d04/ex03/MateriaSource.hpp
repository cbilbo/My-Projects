/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:41:36 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/14 16:59:57 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource: public IMateriaSource
{
private:
	AMateria *_m[4];

public:
	MateriaSource();
	~MateriaSource();
	void	learnMateria(AMateria *m);
	AMateria *createMateria(std::string const &type);
};