/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:32:26 by cbilbo            #+#    #+#             */
/*   Updated: 2021/09/13 16:01:00 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/phil.h"

void	*check_exit(void *pid)
{
	pid_t	out;

	out = waitpid(*(pid_t *)pid, NULL, 0);
	if (out == -1)
		printf("ERROR: pid failed\n");
	return (NULL);
}

void	*pids(void *phs)
{
	t_phl		*phl;
	pthread_t	*philos;
	int			i;

	phl = phs;
	i = -1;
	philos = ft_calloc(phl->nop, sizeof(pthread_t));
	check_memory(phl, (void *)philos);
	while (++i < phl->nop)
	{
		if (pthread_create(&philos[i], NULL, check_exit, &phl->pids[i]))
			free_phl(phl, 't');
	}
	i = -1;
	while (++i < phl->nop)
	{
		if (pthread_join(philos[i], NULL))
			free_phl(phl, 't');
	}
	ft_allocfree((void *)&philos);
	sem_post(phl->death);
	return (NULL);
}

void	start_process(t_phl *phl)
{
	int	phil;
	int	i;

	i = -1;
	while (++i < phl->nop)
	{
		phil = fork();
		if (phil == -1)
			free_phl(phl, 'p');
		if (phil == 0)
		{
			phl->phil[i]->lam = get_time();
			life(phl, phl->phil[i]);
		}
		else
			phl->pids[i] = phil;
	}
}

int	start_processes(t_phl *phl)
{
	pthread_t	monitor;

	phl->time = get_time();
	start_process(phl);
	if (pthread_create(&monitor, NULL, pids, (void *)phl) || \
		pthread_detach(monitor))
	{
		printf("Error\nProblems with threads\n");
		return (0);
	}
	sem_wait(phl->death);
	return (0);
}

int	main(int ac, char **av)
{
	t_phl	*phl;

	phl = start_phl(ac, av);
	if (phl)
	{
		start_processes(phl);
		free_phl(phl, 0);
	}
	return (0);
}
