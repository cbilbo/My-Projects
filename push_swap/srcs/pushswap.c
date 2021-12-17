/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:52:44 by cbilbo            #+#    #+#             */
/*   Updated: 2021/07/27 12:27:30 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	ft_errsps(t_ps *ps, char *c)
{
	int		i;

	i = -1;
	if (c)
	{
		if (c[0] == 'm')
			write(1, "Error\nMemory error\n", 20);
		else if (c[0] == 'w')
			write(1, "Error\nWrong arg\n", 17);
		else if (c[0] == 'g')
			write(1, "Error\nBigger/Smaller than int\n", 31);
		else if (c[0] == 'd')
			write(1, "Error\nDouble int\n", 18);
	}
	else
	{
		while (ps->srt->put[++i] != '\0')
			write(1, &ps->srt->put[i], 1);
	}
	clear_tort(ps, ps->srt);
	ft_allocfree((void *)&ps->stack);
	ft_allocfree((void *)&ps);
	exit (0);
}

void	allrot(t_ort *srt, t_ps *temp, char c)
{
	rotsort(temp, tortcpy(srt, c), c);
	revrotsort(temp, tortcpy(srt, c), c);
}

t_ort	*checkrot(t_ps *ps, t_ort *srt, char c, int i)
{
	t_ps	*temp;
	char	*tmp;

	temp = (t_ps *)ft_calloc(1, sizeof(t_ps));
	if (!temp)
		ft_errsps(ps, "m");
	temp->stack = ps->stack;
	temp->num = ps->num;
	temp->srt = tortcpy(srt, c);
	if (i <= 3)
		swap_small(temp, temp->srt, c, i);
	else
		allrot(srt, temp, c);
	if (temp->srt->len != 0)
	{
		tmp = srt->put;
		srt->put = ft_strjoin(srt->put, temp->srt->put);
		ft_allocfree((void *)&tmp);
		ft_lstclear(&srt->a, 0);
		srt->a = ft_lstcpy(temp->srt->a);
		srt->len += temp->srt->len;
	}
	temp->srt = clear_tort(temp, temp->srt);
	ft_allocfree((void *)&temp);
	return (srt);
}

void	pushswap(t_ps *ps)
{
	if (!ft_lstorder(ps->srt->a))
		ft_errsps(ps, 0);
	if (ps->num <= 3)
	{
		ps->srt = check_srt(ps, ps->srt);
		swap_small(ps, ps->srt, 'a', ps->num);
	}
	else
	{
		rotsort(ps, put_tort(ps), 'a');
		revrotsort(ps, put_tort(ps), 'a');
		if (ps->num < 50)
		{
			bubsort_ps(ps, put_tort(ps), 'a');
			countsort(ps, put_tort(ps));
			rcountsort(ps, put_tort(ps));
			revcountsort(ps, put_tort(ps));
			rrevcountsort(ps, put_tort(ps));
		}
		binradsort(ps, put_tort(ps), 1);
		while (ps->lolkek++ < ps->cheburek)
			inssort(ps, put_tort(ps), 0);
	}	
}

int	main(int argc, char **argv)
{
	t_ps	*ps;

	if (argc < 2)
	{
		write(1, "Error\nNot enough args\n", 23);
		return (0);
	}
	ps = start_ps(argc, argv);
	if (ps)
		pushswap(ps);
	ft_errsps(ps, 0);
	return (0);
}
