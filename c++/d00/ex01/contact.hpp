/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:27:23 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/08 16:27:24 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP 
# include <string>

class contact
{
public:
	contact();
	~contact();
	void	setIndex(int idx);
	int	getIndex(void);
	void	setFiname(std::string finame);
	std::string	getFiname(void);
	void	setLaname(std::string laname);
	std::string	getLaname(void);
	void	setNickname(std::string nickname);
	std::string	getNickname(void);
	void	setNumber(std::string number);
	std::string	getNumber(void);
	void	setSecret(std::string secret);
	std::string	getSecret(void);
	void	showContact(bool s);
private:
	int			_index;
	std::string	_finame;
	std::string	_laname;
	std::string	_nickname;
	std::string	_number;
	std::string	_secret;
};

void	printHeader(bool s);
#endif