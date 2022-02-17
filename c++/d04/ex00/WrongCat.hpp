/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:39:14 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/13 16:50:04 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "WrongAnimal.hpp"
# include <string>
# include <iostream>

class WrongCat: public WrongAnimal 
{
public:
	WrongCat(const std::string &name = "WrongCat");
	WrongCat(const WrongCat &copy);
	WrongCat	&operator=(const WrongCat &src);
	~WrongCat();
	void	makeSound(void) const;
};
