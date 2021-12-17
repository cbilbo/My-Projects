/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:31:10 by cbilbo            #+#    #+#             */
/*   Updated: 2021/09/10 15:24:04 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/phil.h"

void	printerror(char c)
{
	if (c == 'n')
		printf("Error\nWrong number of args\n");
	if (c == 'm')
		printf("Error\nMemory error\n");
	if (c == 'p')
		printf("Error\nProblems with number of philosophers\n");
	if (c == 'd')
		printf("Error\nProblems with time of dying\n");
	if (c == 'e')
		printf("Error\nProblems with time for eating\n");
	if (c == 's')
		printf("Error\nProblems with time for sleeping\n");
	if (c == 'i')
		printf("Error\nProblems with number of meals\n");
	if (c == 'x')
		printf("Error\nProblems with create mutex\n");
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
