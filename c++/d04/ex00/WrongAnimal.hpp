/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:37:51 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/13 16:46:21 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>
# include <iostream>

class WrongAnimal
{
protected:
	std::string _type;
public:
	WrongAnimal(const std::string &name = "WrongAnimal");
	WrongAnimal(const WrongAnimal &copy);
	WrongAnimal	&operator=(const WrongAnimal &src);
	void	setType(const std::string &name);
	std::string	getType(void) const;
	void	makeSound() const;
	~WrongAnimal();
};
