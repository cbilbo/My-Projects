/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:05:29 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/13 20:47:34 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>
# include <iostream>

class Animal
{
protected:
	std::string _type;
	Animal(const std::string &name = "Animal");
	Animal(const Animal &copy);
	virtual Animal	&operator=(const Animal &src);
	virtual ~Animal();	
public:
	void	setType(const std::string &name);
	std::string	getType(void) const;
	virtual void	makeSound() const = 0;
};
