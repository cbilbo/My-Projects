/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:31:10 by cbilbo            #+#    #+#             */
/*   Updated: 2021/09/13 16:01:32 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/phil.h"

void	sem_switch(t_phl *phl, t_phil *phil, int i)
{
	if (i == 1)
	{
		sem_wait(phl->taf);
		sem_wait(phl->forks);
		printmess(phl, phil, "has taken a fork", 0);
		sem_wait(phl->forks);
		printmess(phl, phil, "has taken a fork", 1);
		sem_post(phl->taf);
		return ;
	}
	sem_post(phl->forks);
	sem_post(phl->forks);
}

void	ft_allocfree(void **string)
{
	if (*string)
	{
		free(*string);
		*string = NULL;
	}
}

void	*ft_calloc(size_t num, size_t size)
{
	void	*result;

	result = (void *)malloc(num * size);
	if (!result)
		return (NULL);
	result = memset(result, 0, num * size);
	return (result);
}

long long	get_time(void)
{
	struct timeval	tv;
	long long		time;

	gettimeofday(&tv, NULL);
	time = (long long)tv.tv_sec * 1000 + (long long)tv.tv_usec * 0.001;
	return (time);
}

void	my_usleep(long long time)
{
	long long	t;
	long long	f;

	t = get_time();
	f = get_time();
	if (!time)
		return ;
	while (f - t < time)
	{
		usleep(100);
		f = get_time();
	}
}
