/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inssort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 12:14:14 by cbilbo            #+#    #+#             */
/*   Updated: 2021/07/26 12:15:46 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	ft_lstfstpos(t_list *list, int fst, int lst)
{
	int	i;

	i = 1;
	while (list)
	{
		if (fst <= *(int *)list->content && *(int *)list->content < lst)
			return (i);
		i++;
		list = list->next;
	}
	return (0);
}

int	ft_lstlstpos(t_list *list, int fst, int lst)
{
	t_list	*temp;
	int		i;
	int		j;
	int		k;

	i = ft_lstsize(list);
	j = i - 1;
	while (j != 0)
	{
		k = 0;
		temp = list;
		while (k++ < j)
			temp = temp->next;
		if (*(int *)temp->content < fst || *(int *)temp->content > lst)
			j--;
		else
			return (j);
	}
	return (i);
}

int	findmin(int *arr, int len, int num, int srtsize)
{
	int	i;

	while (num > 0)
	{
		num -= 1;
		i = -1;
		while (++i < len)
		{
			if (arr[i] == num)
				return (i);
		}
	}
	while (num < srtsize)
	{
		num += 1;
		i = -1;
		while (++i < len)
		{
			if (arr[i] == num)
				return (i + 1);
		}
	}
	return (0);
}

int	findmax(int *arr, int len, int num, int srtsize)
{
	int	i;

	while (num > 0)
	{
		num -= 1;
		i = len;
		while (--i > -1)
		{
			if (arr[i] == num)
				return (len - i);
		}
	}
	while (num < srtsize)
	{
		num += 1;
		i = len;
		while (--i > -1)
		{
			if (arr[i] == num)
				return (len - i - 1);
		}
	}
	return (0);
}

int	*pullarr(t_ps *ps, t_ort *srt)
{
	int		*arr;
	t_list	*temp;
	int		i;

	i = 0;
	temp = srt->b;
	arr = (int *)ft_calloc(ft_lstsize(srt->b), sizeof(int));
	if (!arr)
	{
		clear_tort(ps, srt);
		ft_errsps(ps, "m");
	}
	while (temp)
	{
		arr[i++] = *(int *)temp->content;
		temp = temp->next;
	}
	return (arr);
}
