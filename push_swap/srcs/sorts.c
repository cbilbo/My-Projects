/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 12:19:32 by cbilbo            #+#    #+#             */
/*   Updated: 2021/07/26 15:44:33 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

t_ort	*bubsort_ps(t_ps *ps, t_ort *srt, char c)
{
	int		i;

	i = 0;
	if (!ft_lstorder(srt->a))
		return (srt);
	while (i++ < ps->num - 1)
	{
		if (!ft_lstorder(srt->a))
			break ;
		if (*(int *)(srt->a)->content > *(int *)(srt->a)->next->content)
		{
			srt->len += sf(ps, srt, c);
			srt = checkrot(ps, srt, 'a', ps->num);
			if (!ft_lstorder(srt->a))
				break ;
		}
		srt->len += rot(ps, srt, c);
	}
	if (ft_lstorder(srt->a))
		srt->len += rot(ps, srt, c);
	srt = bubsort_ps(ps, srt, c);
	ps->srt = check_srt(ps, srt);
	return (NULL);
}

t_ort	*binradsort(t_ps *ps, t_ort *srt, int bin)
{
	int	i;

	i = 0;
	while (i++ < ps->num)
	{
		if (!(*(int *)srt->a->content & bin))
			srt->len += pf(ps, srt, 'b');
		else
			srt->len += rot(ps, srt, 'a');
	}
	while (srt->b != NULL)
	{
		srt->len += pf(ps, srt, 'a');
	}
	if (ft_lstorder(srt->a))
		srt = binradsort(ps, srt, bin << 1);
	ps->srt = check_srt(ps, srt);
	return (NULL);
}
