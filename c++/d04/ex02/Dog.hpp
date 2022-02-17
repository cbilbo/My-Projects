/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:20:02 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/13 20:37:08 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "Animal.hpp"
# include "Brain.hpp"
# include <string>
# include <iostream>

class Dog: public Animal
{
private:
	Brain	*_brain;
public:
	Dog(const std::string &name = "Dog");
	Dog(const Dog &copy);
	Dog	&operator=(const Dog &src);
	~Dog();
	void	makeSound() const;
	void setIdeaToBrain(const std::string &idea, int pos);
	std::string	getIdeaFromBrain(int pos) const;
};