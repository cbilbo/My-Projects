/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:03:21 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/13 21:08:46 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"		
#include <string>

int main(void)
{
	std::cout << "\n==============================\n\n";
	{
		Animal	error();
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