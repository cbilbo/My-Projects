/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 10:52:29 by cbilbo            #+#    #+#             */
/*   Updated: 2021/07/26 10:52:32 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

t_ort	*clear_tort(t_ps *ps, t_ort *srt)
{
	if (!ps->stack || !srt)
		return (NULL);
	if (srt->a)
		ft_lstclear(&srt->a, 0);
	if (srt->b)
		ft_lstclear(&srt->b, 0);
	if (srt)
		ft_allocfree((void *)&srt->put);
	ft_allocfree((void *)&srt);
	return (srt);
}

t_ort	*put_tort(t_ps *ps)
{
	t_ort	*res;
	int		i;

	i = -1;
	res = (t_ort *)ft_calloc(1, sizeof(t_ort));
	if (!res)
		ft_errsps(ps, "m");
	res->put = ft_strdup("\0");
	if (!res->put)
		ft_errsps(ps, "m");
	res->len = 0;
	while (++i < ps->num)
		ft_lstadd_back(&res->a, ft_lstnew((void *)&ps->stack[i]));
	return (res);
}

t_ort	*check_srt(t_ps *ps, t_ort *srt)
{
	if ((ps->srt && ps->srt == srt) || srt == NULL)
		return (ps->srt);
	if (!ps->srt || ps->srt->len > srt->len || ps->srt->len >= 69696969 \
		|| !ps->srt->len)
	{
		ps->srt = clear_tort(ps, ps->srt);
		ps->srt = srt;
		return (ps->srt);
	}
	srt = clear_tort(ps, srt);
	return (ps->srt);
}

t_list	*ft_lstcpy(t_list *src)
{
	t_list	*res;

	res = NULL;
	if (!src)
		return (NULL);
	while (src)
	{
		ft_lstadd_back(&res, ft_lstnew(src->content));
		src = src->next;
	}
	return (res);
}

t_ort	*tortcpy(t_ort *srt, char c)
{
	t_ort	*res;

	res = (t_ort *)ft_calloc(1, sizeof(t_ort));
	if (!res)
		return (NULL);
	res->a = ft_lstcpy(srt->a);
	res->b = ft_lstcpy(srt->b);
	if (!c)
	{
		res->put = ft_strdup(srt->put);
		res->len = srt->len;
	}
	else
	{
		res->put = ft_strdup("\0");
		res->len = 0;
	}
	return (res);
}
