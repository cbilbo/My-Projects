/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countsorts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 12:16:13 by cbilbo            #+#    #+#             */
/*   Updated: 2021/07/27 00:43:45 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	countsort(t_ps *ps, t_ort *srt)
{
	int	i;

	while (ft_lstsize(srt->a) > 3)
	{
		if (*(int *)srt->a->content > 2)
			srt->len += pf(ps, srt, 'b');
		else
			srt->len += rot(ps, srt, 'a');
	}
	srt = checkrot(ps, srt, 'a', 3);
	i = 3;
	while (ft_lstsize(srt->a) != ps->num)
	{
		if (*(int *)srt->b->content == i && i++)
		{
			srt->len += pf(ps, srt, 'a');
			srt->len += rot(ps, srt, 'a');
		}
		else if (*(int *)srt->b->content > *(int *)srt->b->next->content)
			srt->len += sf(ps, srt, 'b');
		else
			srt->len += rot(ps, srt, 'b');
	}
	ps->srt = check_srt(ps, srt);
}

void	rcountsort(t_ps *ps, t_ort *srt)
{
	int	i;

	while (ft_lstsize(srt->a) > 3)
	{
		if (*(int *)srt->a->content > 2)
			srt->len += pf(ps, srt, 'b');
		else
			srt->len += rot(ps, srt, 'a');
	}
	srt = checkrot(ps, srt, 'a', 3);
	i = 3;
	while (ft_lstsize(srt->a) != ps->num)
	{
		if (*(int *)srt->b->content == i && i++)
		{
			srt->len += pf(ps, srt, 'a');
			srt->len += rot(ps, srt, 'a');
		}
		else if (*(int *)srt->b->content > *(int *)srt->b->next->content)
			srt->len += sf(ps, srt, 'b');
		else
			srt->len += revrot(ps, srt, 'b');
	}
	ps->srt = check_srt(ps, srt);
}

void	rrevcountsort(t_ps *ps, t_ort *srt)
{
	int	i;

	i = ps->num;
	while (ft_lstsize(srt->a) != 3)
	{
		if (*(int *)srt->a->content < ps->num - 3)
			srt->len += pf(ps, srt, 'b');
		if (ft_lstsize(srt->a) != 3)
			srt->len += revrot(ps, srt, 'a');
	}
	i = ps->num - 3;
	srt = checkrot(ps, srt, 'a', 3);
	while (srt->b)
	{
		if (*(int *)srt->b->content == i - 1 && i--)
			srt->len += pf(ps, srt, 'a');
		else if (*(int *)srt->b->content > *(int *)srt->b->next->content)
			srt->len += sf(ps, srt, 'b');
		else
			srt->len += revrot(ps, srt, 'b');
	}
	ps->srt = check_srt(ps, srt);
}	

void	revcountsort(t_ps *ps, t_ort *srt)
{
	int	i;

	while (ft_lstsize(srt->a) != 3)
	{
		if (*(int *)srt->a->content < ps->num - 3)
			srt->len += pf(ps, srt, 'b');
		if (ft_lstsize(srt->a) != 3)
			srt->len += revrot(ps, srt, 'a');
	}
	srt = checkrot(ps, srt, 'a', 3);
	i = ps->num - 3;
	while (srt->b)
	{
		if (*(int *)srt->b->content == i - 1 && i--)
			srt->len += pf(ps, srt, 'a');
		else if (*(int *)srt->b->content > *(int *)srt->b->next->content)
			srt->len += sf(ps, srt, 'b');
		else
			srt->len += rot(ps, srt, 'b');
	}
	ps->srt = check_srt(ps, srt);
}
