/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inssort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 12:09:55 by cbilbo            #+#    #+#             */
/*   Updated: 2021/07/26 15:49:39 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	putinorder(t_ps *ps, t_ort *srt, int num)
{
	int		*arr;
	int		ord;
	int		min;
	int		max;

	arr = pullarr(ps, srt);
	min = findmin(arr, ft_lstsize(srt->b), num, ps->num);
	max = findmax(arr, ft_lstsize(srt->b), num, ps->num);
	ord = ft_ter_i(min <= max, 1, 2);
	while (ord == 1 && min--)
		srt->len += rot(ps, srt, 'b');
	while (ord == 2 && max--)
		srt->len += revrot(ps, srt, 'b');
	srt->len += pf(ps, srt, 'b');
	ft_allocfree((void *)&arr);
}

void	pushback(t_ps *ps, t_ort *srt)
{
	int		*arr;
	int		ord;
	int		min;
	int		max;
	int		len;

	len = ft_lstsize(srt->b);
	arr = pullarr(ps, srt);
	min = findmin(arr, len, len, ps->num);
	max = findmax(arr, len, len, ps->num);
	ord = ft_ter_i(min <= max, 1, 2);
	while (ord == 1 && min--)
		srt->len += rot(ps, srt, 'b');
	while (ord == 2 && max--)
		srt->len += revrot(ps, srt, 'b');
	while (srt->b)
		srt->len += pf(ps, srt, 'a');
	ft_allocfree((void *)&arr);
}

int	findaerial(t_ps *ps, t_ort *srt, int fst, int lst)
{
	int	fp;
	int	lp;
	int	ord;

	fp = ft_lstfstpos(srt->a, fst, lst);
	lp = ft_lstlstpos(srt->a, fst, lst);
	ord = ft_ter_i(fp <= (ft_lstsize(srt->a) - lp) + (lp - fp), 1, 2);
	while (ord == 1 && --fp)
		srt->len += rot(ps, srt, 'a');
	while (ord == 2 && ft_lstsize(srt->a) + 1 - fp++)
		srt->len += revrot(ps, srt, 'a');
	return (ord);
}

void	mvlists(t_ps *ps, t_ort *srt, int ord, int fst)
{
	int	i;
	int	j;
	int	l;

	i = ft_ter_i(fst + (ps->lolkek) < ps->num, fst + \
		(ps->lolkek), ps->num - 1);
	l = i - fst;
	if (!srt->b && l--)
		srt->len += pf(ps, srt, 'b');
	while (l)
	{
		j = 0;
		if (*(int *)srt->a->content >= i)
		{
			if (ord == 1)
				srt->len += rot(ps, srt, 'a');
			else
				srt->len += revrot(ps, srt, 'a');
			continue ;
		}
		putinorder(ps, srt, *(int *)srt->a->content);
		l--;
	}
}

t_ort	*inssort(t_ps *ps, t_ort *srt, int dia)
{
	int	lst;
	int	ord;

	lst = ft_ter_i(dia + (ps->lolkek) < ps->num, \
		dia + (ps->lolkek), ps->num - 1);
	if (srt->b && ((!srt->a && !ft_lstrevorder(srt->b)) \
		|| !ft_lstorder(srt->a)))
	{
		while (srt->b)
			pushback(ps, srt);
		ps->srt = check_srt(ps, srt);
		return (NULL);
	}
	ord = findaerial(ps, srt, dia, lst);
	mvlists(ps, srt, ord, dia);
	return (inssort(ps, srt, lst));
}
