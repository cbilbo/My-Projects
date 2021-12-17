/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstorder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 19:42:41 by cbilbo            #+#    #+#             */
/*   Updated: 2021/07/26 15:45:41 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstorder(t_list *list)
{
	while (list->next)
	{
		if (*(int *)list->content > *(int *)list->next->content)
			return (1);
		list = list->next;
	}
	return (0);
}
