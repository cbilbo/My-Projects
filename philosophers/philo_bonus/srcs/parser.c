/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:32:28 by cbilbo            #+#    #+#             */
/*   Updated: 2021/09/13 15:58:18 by cbilbo           ###   ########.fr       */
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
	if (phl->phil[0])
	{
		sem_close(phl->dead);
		sem_close(phl->print);
		sem_close(phl->forks);
		sem_close(phl->death);
		sem_close(phl->taf);
		while (++i < phl->nop)
		{
			kill(phl->pids[i], SIGKILL);
			ft_allocfree((void *)&phl->phil[i]);
		}
	}
	ft_allocfree((void *)&phl->phil);
	ft_allocfree((void *)&phl->pids);
	ft_allocfree((void *)&phl);
	exit (0);
	return (NULL);
}

t_phl	*fill_forks(t_phl *phl)
{
	phl->pids = ft_calloc(phl->nop, sizeof(pid_t));
	check_memory(phl, (void *)phl->pids);
	if (sem_unlink("/forks") || sem_unlink("/dead") || sem_unlink("/print") \
		|| sem_unlink("/death") || sem_unlink("/taf"))
		return (free_phl(phl, 's'));
	phl->forks = sem_open("/forks", O_CREAT, 0660, phl->nop);
	phl->dead = sem_open("/dead", O_CREAT, 0660, 1);
	phl->print = sem_open("/print", O_CREAT, 0660, 1);
	phl->death = sem_open("/death", O_CREAT, 0660, 0);
	phl->taf = sem_open("/taf", O_CREAT, 0660, 1);
	if (phl->forks == SEM_FAILED || phl->dead == SEM_FAILED || \
		phl->print == SEM_FAILED || phl->death == SEM_FAILED || \
		phl->taf == SEM_FAILED)
		return (free_phl(phl, 's'));
	return (phl);
}

t_phl	*fill_phil(t_phl *phl)
{
	int	i;

	i = -1;
	phl->phil = (t_phil **)ft_calloc(phl->nop, sizeof(t_phil *));
	check_memory(phl, (void *)phl->phil);
	while (++i < phl->nop)
	{
		phl->phil[i] = (t_phil *)ft_calloc(1, sizeof(t_phil));
		check_memory(phl, (void *)phl->phil[i]);
		phl->phil[i]->id = i + 1;
		phl->phil[i]->meals = 0;
		phl->phil[i]->phl = phl;
	}
	return (fill_forks(phl));
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
	check_memory(phl, (void *)phl);
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
	return (fill_phil(phl));
}
