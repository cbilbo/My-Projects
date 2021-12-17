/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 18:46:36 by cbilbo            #+#    #+#             */
/*   Updated: 2021/07/27 11:49:24 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	*putstack(t_ps *ps, t_list *list)
{
	int		*arr;
	t_list	*temp;
	int		i;

	i = -1;
	temp = list;
	arr = (int *)malloc(ft_lstsize(list) * sizeof(int));
	if (!arr)
		ft_errsps(ps, "m");
	while (++i < ft_lstsize(list))
	{
		arr[i] = *(int *)temp->content;
		temp = temp->next;
	}
	return (arr);
}

int	check_arg(char **str, int num)
{
	int		len;
	char	*res;

	res = *str;
	len = ft_ter_i(num < 0, ft_nbrlen(num) - 1, ft_nbrlen(num));
	if (*res == '-')
		res++;
	while ((num != 0 && *res == '0'))
		res++;
	while (len--)
		res++;
	if (num == 0)
	{
		while (*res == '0')
			res++;
		*str = res;
		return (0);
	}
	if ((num == 0 && **str == '-') || (num == -1 && **str != '-'))
		return (1);
	*str = res;
	return (0);
}
