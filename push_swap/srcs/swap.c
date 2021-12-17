/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:52:47 by cbilbo            #+#    #+#             */
/*   Updated: 2021/07/27 11:48:41 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	swap_first_element(t_ort *srt, char s)
{
	t_list	*temp;

	if (s == 'a')
	{
		temp = srt->b;
		srt->b = srt->b->next;
		temp->next = srt->a;
		srt->a = temp;
	}
	else
	{
		temp = srt->a;
		srt->a = srt->a->next;
		temp->next = srt->b;
		srt->b = temp;
	}
}

int	sf(t_ps *ps, t_ort *srt, char s)
{
	char	str[4];
	char	*temp;

	ft_memcpy(str, "sa\n\0", 4);
	str[1] = s;
	if (s == 'a')
		srt->a = toplist(srt->a);
	if (s == 'b')
		srt->b = toplist(srt->b);
	if (s == 's')
	{
		srt->a = toplist(srt->a);
		srt->b = toplist(srt->b);
	}
	if ((s == 'a' && !srt->a) || (s == 'b' && !srt->b) || (s == 's' && \
		(!srt->a || !srt->b)))
		ft_errsps(ps, "m");
	temp = ft_strjoin(srt->put, str);
	ft_allocfree((void *)&srt->put);
	srt->put = temp;
	if (!srt->put)
		ft_errsps(ps, "m");
	return (1);
}

int	pf(t_ps *ps, t_ort *srt, char s)
{
	char	str[4];
	char	*tmp;

	ft_memcpy(str, "pa\n\0", 4);
	str[1] = s;
	if ((s == 'a' && !srt->b) || (s == 'b' && !srt->a))
		return (0);
	swap_first_element(srt, s);
	tmp = ft_strjoin(srt->put, str);
	ft_allocfree((void *)&srt->put);
	srt->put = tmp;
	if (!srt->put)
		ft_errsps(ps, "m");
	return (1);
}

int	rot(t_ps *ps, t_ort *srt, char s)
{
	char	str[4];
	char	*temp;

	ft_memcpy(str, "ra\n\0", 4);
	str[1] = s;
	if (s == 'a')
		srt->a = rotate(srt->a);
	if (s == 'b')
		srt->b = rotate(srt->b);
	if (s == 'r')
	{
		srt->a = rotate(srt->a);
		srt->b = rotate(srt->b);
	}
	temp = ft_strjoin(srt->put, str);
	ft_allocfree((void *)&srt->put);
	srt->put = temp;
	if (!srt->put)
		ft_errsps(ps, "m");
	return (1);
}

int	revrot(t_ps *ps, t_ort *srt, char s)
{
	char	str[5];
	char	*temp;

	ft_memcpy(str, "rra\n\0", 5);
	str[2] = s;
	if (s == 'a')
		srt->a = revrotate(srt->a);
	if (s == 'b')
		srt->b = revrotate(srt->b);
	if (s == 'r')
	{
		srt->a = revrotate(srt->a);
		srt->b = revrotate(srt->b);
	}
	temp = ft_strjoin(srt->put, str);
	ft_allocfree((void *)&srt->put);
	srt->put = temp;
	if (!srt->put)
		ft_errsps(ps, "m");
	return (1);
}
