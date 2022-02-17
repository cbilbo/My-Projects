/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:27:33 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/08 16:27:34 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "contact.hpp"

class phonebook
{
public:
	phonebook();
	~phonebook();
	void	addContact(int idx);
	void	showPhonebook(void);
	void	setContact(contact cnt);
	contact getContact(int idx);
	bool	findContact(int idx);
private:
	contact _contacts[8];
};

void	checkeof(void);
#endif