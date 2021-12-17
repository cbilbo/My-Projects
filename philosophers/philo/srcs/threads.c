/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:32:22 by cbilbo            #+#    #+#             */
/*   Updated: 2021/10/18 15:42:59 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/phil.h"

void	*printmess(t_phl *phl, int id, char *s, int c)
{
	long long	time;

	if (phl && !phl->ded)
	{
		pthread_mutex_lock(&phl->fork[phl->nop]);
		time = get_time() - phl->time;
		if (phl && !phl->ded)
		{
			if (c == 0)
				printf(R"%lld %d %s\n"RESET, time, id, s);
			else if (c == 1)
				printf(B"%lld %d %s\n"RESET, time, id, s);
			else if (c == 2)
				printf(G"%lld %d %s\n"RESET, time, id, s);
			else if (c == 3)
				printf(Y"%lld %d %s\n"RESET, time, id, s);
			else if (c == 4)
				printf(P"%lld %d %s\n"RESET, time, id, s);
		}
		pthread_mutex_unlock(&phl->fork[phl->nop]);
	}
	return (NULL);
}

void	*life(void *phil)
{
	t_phil	*one;

	one = phil;
	while (one->phl)
	{
		pthread_mutex_lock(&one->phl->taf);
		pthread_mutex_lock(one->left);
		printmess(one->phl, one->id, "has taken a fork", 0);
		pthread_mutex_lock(one->right);
		printmess(one->phl, one->id, "has taken a fork", 1);
		pthread_mutex_unlock(&one->phl->taf);
		pthread_mutex_lock(&one->is_dead);
		printmess(one->phl, one->id, "is eating", 3);
		one->lam = get_time();
		my_usleep(one->phl->eat);
		pthread_mutex_unlock(&one->is_dead);
		pthread_mutex_unlock(one->right);
		pthread_mutex_unlock(one->left);
		if (++one->meals == one->phl->nom)
			one->phl->nof++;
		printmess(one->phl, one->id, "is sleeping", 2);
		my_usleep(one->phl->son);
		printmess(one->phl, one->id, "is thinking", 4);
	}
	return (NULL);
}

void	start_phil(t_phl *phl, int i)
{
	phl->phil[i]->lam = phl->time;
	pthread_create(&phl->phil[i]->osoph, NULL, life, (void *)phl->phil[i]);
	pthread_detach(phl->phil[i]->osoph);
}

void	*monitor(t_phl *phl)
{
	int			i;
	int			die;
	long long	now;

	die = 0;
	while (1)
	{
		now = get_time();
		i = -1;
		while (++i < phl->nop)
		{
			if ((long long)phl->die < (now - phl->phil[i]->lam))
			{
				pthread_mutex_lock(&phl->fork[phl->nop]);
				pthread_mutex_lock(&phl->phil[i]->is_dead);
				printf(C"%lld %d %s\n"RESET, now - phl->time, i + 1, "is dead");
				phl->ded++;
				return (NULL);
			}
		}
		if (phl->ded == 1 || phl->nof == phl->nop)
			return (NULL);
	}
	return (NULL);
}

int	start_threads(t_phl *phl)
{
	int			i;

	phl->time = get_time();
	i = 0;
	while (i < phl->nop)
	{
		start_phil(phl, i);
		i += 2;
	}
	i = 1;
	while (i < phl->nop)
	{
		start_phil(phl, i);
		i += 2;
	}
	monitor(phl);
	return (0);
}
