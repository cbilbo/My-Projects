/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 15:08:15 by cbilbo            #+#    #+#             */
/*   Updated: 2021/07/27 10:57:17 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void **))
{
	t_list	*list;
	t_list	*temp;

	list = *lst;
	while (list)
	{
		temp = list->next;
		if (del)
			del(&list->content);
		free(list);
		list = temp;
	}
	*lst = NULL;
}
