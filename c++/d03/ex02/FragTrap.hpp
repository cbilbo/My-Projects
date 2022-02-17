/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:21:30 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/10 18:38:16 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "ClapTrap.hpp"
# include <string>

class FragTrap: public ClapTrap
{
private:
public:
	FragTrap();
	FragTrap(std::string const &name);
	FragTrap(FragTrap const &copy);
	~FragTrap();
	
	void	attack(std::string const &target);
	void	highFivesGuys(void);

	FragTrap &operator = (FragTrap const &trap);	
};