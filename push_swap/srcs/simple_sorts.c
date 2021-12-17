/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sorts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 20:53:38 by cbilbo            #+#    #+#             */
/*   Updated: 2021/07/27 11:50:03 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	rotsort(t_ps *ps, t_ort *srt, char c)
{
	int		i;
	t_list	**list;

	list = ft_lstaddr(c == 'a', &(srt->a), &(srt->b));
	i = 0;
	while (i++ < ps->num)
	{
		srt->len += rot(ps, srt, c);
		if (!ft_lstorder(*list))
		{
			ps->srt = check_srt(ps, srt);
			return ;
		}
	}
	srt = clear_tort(ps, srt);
}

void	revrotsort(t_ps *ps, t_ort *srt, char c)
{
	int		i;
	t_list	**list;

	list = ft_lstaddr(c == 'a', &(srt->a), &(srt->b));
	i = 0;
	while (i++ < ps->num)
	{
		srt->len += revrot(ps, srt, c);
		if (!ft_lstorder(*list))
		{
			ps->srt = check_srt(ps, srt);
			return ;
		}
	}
	srt = clear_tort(ps, srt);
}

void	swap_three(t_ps *ps, t_list *head, char c)
{
	int	one;
	int	two;
	int	three;

	one = *(int *)head->content;
	two = *(int *)head->next->content;
	three = *(int *)head->next->next->content;
	if (one < two)
		ps->srt->len += revrot(ps, ps->srt, c);
	if (one < three)
		ps->srt->len += sf(ps, ps->srt, c);
	if (one > three && one > two)
	{
		ps->srt->len += rot(ps, ps->srt, c);
		if (two > three)
			ps->srt->len += sf(ps, ps->srt, c);
	}
}

void	swap_small(t_ps *ps, t_ort *srt, char c, int num)
{
	if (num == 2 && ft_lstorder(srt->a))
		ps->srt->len += sf(ps, srt, c);
	else if (num == 3 && ft_lstorder(srt->a))
		swap_three(ps, srt->a, c);
}
