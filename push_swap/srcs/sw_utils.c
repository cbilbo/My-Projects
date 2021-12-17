/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:52:50 by cbilbo            #+#    #+#             */
/*   Updated: 2021/07/26 15:48:52 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

t_list	*toplist(t_list *head)
{
	t_list	*temp;

	if (!head || !head->next)
		return (NULL);
	temp = head->next;
	head->next = temp->next;
	temp->next = head;
	return (temp);
}

t_list	*rotate(t_list *head)
{
	t_list	*temp;

	if (!head || !head->next)
		return (head);
	temp = head;
	head = head->next;
	temp->next = NULL;
	ft_lstadd_back(&head, temp);
	return (head);
}

t_list	*revrotate(t_list *head)
{
	t_list	*temp;
	int		i;

	if (!head || !head->next)
		return (head);
	i = ft_lstsize(head) - 2;
	temp = ft_lstlast(head);
	temp->next = head;
	while (i-- > 0)
		head = head->next;
	head->next = NULL;
	return (temp);
}
