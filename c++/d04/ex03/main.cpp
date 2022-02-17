/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:03:21 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/23 16:53:21 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main(void)
{
	{
		IMateriaSource* src = new MateriaSource();
		AMateria *ice = new Ice();
		AMateria *cure = new Cure();
		src->learnMateria(ice);
		src->learnMateria(ice);
		src->learnMateria(cure);
		src->learnMateria(ice);
		src->learnMateria(cure);
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("ice");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		std::cout << "======\n";
		me->use(0, *bob);
		me->use(1, *bob);
		std::cout << "======1\n";
		ICharacter *jim = new Character(*(dynamic_cast<Character*>(me)));
		jim->use(0, *me);
		jim->use(1, *me);
		std::cout << "======\n";
		me->use(0, *jim);
		jim->use(0, *me);
		jim->unequip(0);
		jim->equip(src->createMateria("cure"));
		me->use(0, *jim);
		jim->use(0, *me);
		delete jim;
		delete cure;
		delete ice;
		delete bob;
		delete me;
		delete src;
	}
	return 0;
}