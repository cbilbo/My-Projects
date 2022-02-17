/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:03:21 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/13 16:51:18 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::cout << "\n==============================\n\n";
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << "\n==============================\n\n";
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		std::cout << "\n==============================\n\n";
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
	}
	std::cout << "\n==============================\n\n";
	{
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();
		std::cout << "\n==============================\n\n";
		std::cout << i->getType() << " " << std::endl;
		std::cout << "\n==============================\n\n";
		i->makeSound(); //will output the cat sound!
		meta->makeSound();
	}
	std::cout << "\n==============================\n\n";
	return (0);
}