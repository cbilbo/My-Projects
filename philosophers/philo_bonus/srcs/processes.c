/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:32:22 by cbilbo            #+#    #+#             */
/*   Updated: 2021/09/13 16:01:21 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/phil.h"

void	*printmess(t_phl *phl, t_phil *phil, char *s, int c)
{
	long long	time;

	if (phl && phil->meals != phl->nom)
	{
		sem_wait(phl->print);
		time = get_time() - phl->time;
		if (phl)
		{
			if (c == 0)
				printf(R"%lld %d %s\n"RESET, time, phil->id, s);
			else if (c == 1)
				printf(B"%lld %d %s\n"RESET, time, phil->id, s);
			else if (c == 2)
				printf(G"%lld %d %s\n"RESET, time, phil->id, s);
			else if (c == 3)
				printf(Y"%lld %d %s\n"RESET, time, phil->id, s);
			else if (c == 4)
				printf(P"%lld %d %s\n"RESET, time, phil->id, s);
		}
		sem_post(phl->print);
	}
	return (NULL);
}

void	*check_death(void *philosoph)
{
	t_phil		*phil;
	long long	now;

	phil = philosoph;
	while (phil)
	{
		now = get_time();
		if ((long long)phil->phl->die < now - phil->lam)
		{
			sem_wait(phil->phl->dead);
			sem_wait(phil->phl->print);
			printf(C"%lld %d %s\n"RESET, now - phil->phl->time, phil->id, \
				"is dead");
			sem_post(phil->phl->death);
			exit (0);
		}
	}
	return (NULL);
}

void	life(t_phl *phl, t_phil *phil)
{
	pthread_t	mon;

	if (pthread_create(&mon, NULL, check_death, phil) || pthread_detach(mon))
	{
		printf("Error\nError with threads\n");
		exit (0);
	}
	while (phil->meals != phl->nom)
	{
		sem_switch(phl, phil, 1);
		sem_wait(phl->dead);
		phil->lam = get_time();
		printmess(phl, phil, "is eating", 3);
		sem_post(phl->dead);
		my_usleep(phl->eat);
		sem_switch(phl, phil, 0);
		phil->meals++;
		printmess(phl, phil, "is sleeping", 2);
		my_usleep(phl->son);
		printmess(phl, phil, "is thinking", 4);
	}
	exit (0);
}
