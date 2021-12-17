/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrevorder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 16:48:51 by cbilbo            #+#    #+#             */
/*   Updated: 2021/07/15 16:54:40 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstrevorder(t_list *list)
{
	while (list->next)
	{
		if (*(int *)list->content < *(int *)list->next->content)
			return (1);
		list = list->next;
	}
	return (0);
}
