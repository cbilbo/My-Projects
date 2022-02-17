/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:03:21 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/23 16:10:43 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	{
		std::cout << "\n==============================\n\n";
		Animal *arr[10];
		for (int i = 0; i < 10; ++i)
		{
			if (i%2)
				arr[i] = new Cat("Cat " + std::to_string(i));
			else
				arr[i] = new Dog("Dog " + std::to_string(i));
			std::cout << "\n==============================\n\n";
		}

		for (int i = 0; i < 10; ++i)
		{
			arr[i]->makeSound();
			delete arr[i];
			std::cout << "\n==============================\n\n";
		}
	}
		std::cout << "\n==============================\n\n";
	{
		Cat a("Cat a");
		std::cout << "\n==============================\n\n";
		a.setIdeaToBrain("I want to eat", 1);
		std::cout << "\n==============================\n\n";
		Cat b = a;
		std::cout << "\n==============================\n\n";
		b.setIdeaToBrain("I want to drink", 1);
		std::cout << "\n==============================\n\n";
		std::cout << "First cat think: " << a.getIdeaFromBrain(1) << 
			"\nSecond cat think: " << b.getIdeaFromBrain(1) << std::endl;
		std::cout << "\n==============================\n\n";
	}
	return (0);
}