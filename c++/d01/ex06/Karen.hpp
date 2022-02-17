/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:26:59 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/08 16:27:00 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
# define KAREN_HPP
# include <string>

class Karen
{
public:
	Karen();
	~Karen();
	void	complain(std::string level);
private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
};

#endif