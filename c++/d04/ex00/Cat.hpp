/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:23:52 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/13 16:32:03 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "Animal.hpp"
# include <string>
# include <iostream>

class Cat: public Animal 
{
public:
	Cat(const std::string &name = "Cat");
	Cat(const Cat &copy);
	Cat	&operator=(const Cat &src);
	~Cat();
	void	makeSound(void) const;
};

