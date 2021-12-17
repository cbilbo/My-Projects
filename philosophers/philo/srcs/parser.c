/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:32:28 by cbilbo            #+#    #+#             */
/*   Updated: 2021/09/13 16:24:55 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/phil.h"

int	ft_args(char *s, char c, char *e)
{
	int	res;
	int	i;

	res = 0;
	i = -1;
	if (!s)
		return (-1);
	while (s[++i] != '\0')
	{
		if (s[i] < 48 || s[i] > 57 || i == 11 || res > 214748364 || \
			(res == 214748364 && s[i] > 55))
		{
			*e = c;
			return (-1);
		}
		res = res * 10 + ((int)s[i] - 48);
	}
	return (res);
}

t_phl	*free_phl(t_phl *phl, char c)
{
	int	i;

	printerror(c);
	if (!phl)
		return (NULL);
	i = -1;
	if (phl->fork)
	{
		usleep(10000);
		if (phl->phil)
		{
			while (++i < phl->nop)
			{
				pthread_mutex_destroy(&phl->fork[i]);
				pthread_mutex_destroy(&phl->phil[i]->is_dead);
				ft_allocfree((void *)&phl->phil[i]);
			}
		}
		pthread_mutex_destroy(&phl->fork[phl->nop]);
	}
	pthread_mutex_destroy(&phl->taf);
	ft_allocfree((void *)&phl->fork);
	ft_allocfree((void *)&phl->phil);
	ft_allocfree((void *)&phl);
	return (NULL);
}

t_phl	*fill_forks(t_phl *phl, int num)
{
	int	i;

	i = num + 1;
	phl->fork = (t_mutex *)malloc(i * sizeof(t_mutex));
	if (!phl->fork)
		return (free_phl(phl, 'm'));
	while (--i >= 0)
		pthread_mutex_init(&phl->fork[i], NULL);
	while (++i < num - 1)
	{
		phl->phil[i]->left = &phl->fork[i];
		phl->phil[i]->right = &phl->fork[i + 1];
		pthread_mutex_init(&phl->phil[i]->is_dead, NULL);
	}
	phl->phil[i]->left = &phl->fork[i];
	phl->phil[i]->right = &phl->fork[0];
	pthread_mutex_init(&phl->phil[i]->is_dead, NULL);
	pthread_mutex_init(&phl->fork[num], NULL);
	pthread_mutex_init(&phl->taf, NULL);
	return (phl);
}

t_phl	*fill_phil(t_phl *phl)
{
	int	i;

	i = -1;
	phl->phil = (t_phil **)ft_calloc(phl->nop, sizeof(t_phil *));
	if (!phl->phil)
		return (free_phl(phl, 'm'));
	while (++i < phl->nop)
	{
		phl->phil[i] = (t_phil *)ft_calloc(1, sizeof(t_phil));
		if (!phl->phil[i])
			return (free_phl(phl, 'm'));
		phl->phil[i]->id = i + 1;
		phl->phil[i]->meals = 0;
		phl->phil[i]->phl = phl;
	}
	return (fill_forks(phl, phl->nop));
}

t_phl	*start_phl(int ac, char **av)
{
	t_phl	*phl;
	char	e;

	phl = NULL;
	e = 'i';
	if (ac != 5 && ac != 6)
		return (free_phl(NULL, 'n'));
	phl = (t_phl *)ft_calloc(1, sizeof(t_phl));
	if (!phl)
		return (free_phl(NULL, 'm'));
	phl->nop = ft_args(av[1], 'p', &e);
	phl->die = ft_args(av[2], 'd', &e);
	phl->eat = ft_args(av[3], 'e', &e);
	phl->son = ft_args(av[4], 's', &e);
	phl->nom = ft_args(av[5], 'i', &e);
	if (phl->nop < 1)
		e = 'p';
	if (phl->nop < 1 || phl->die == -1 || phl->eat == -1 || \
		phl->son == -1 || (phl->nom == -1 && ac == 6))
		return (free_phl(phl, e));
	if (phl->nom == 0)
		return (free_phl(phl, 0));
	phl->ded = 0;
	phl->nof = 0;
	return (fill_phil(phl));
}
