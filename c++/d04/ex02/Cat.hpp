/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:23:52 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/13 20:21:19 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "Animal.hpp"
# include "Brain.hpp"
# include <string>
# include <iostream>

class Cat: public Animal 
{
private:
	Brain	*_brain;
public:
	Cat(const std::string &name = "Cat");
	Cat(const Cat &copy);
	virtual Cat	&operator=(const Cat &src);
	virtual ~Cat();
	void setIdeaToBrain(const std::string &idea, int pos);
	std::string	getIdeaFromBrain(int pos) const;
	
	void	makeSound(void) const;
};

