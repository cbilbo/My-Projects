/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:53:34 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/13 20:21:53 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>

class Brain
{
private:
	std::string	_ideas[100];
	std::string _owner;
public:
	Brain(const std::string &owner = "Abstract");
	Brain(const Brain &copy);
	Brain &operator=(const Brain &brain);
	void setIdea(const std::string &idea, int pos);
	std::string getIdea(int pos) const;
	~Brain();
};