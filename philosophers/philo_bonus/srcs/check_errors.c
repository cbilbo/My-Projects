/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:36:07 by cbilbo            #+#    #+#             */
/*   Updated: 2021/09/13 16:35:06 by cbilbo           ###   ########.fr       */
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
	if (c == 'o')
		printf("Error\nProblems with time for sleeping\n");
	if (c == 'i')
		printf("Error\nProblems with number of meals\n");
	if (c == 'p')
		printf("Error\nProblems with create process\n");
	if (c == 's')
		printf("Error\nProblems with semaphores\n");
}

void	*check_memory(t_phl *phl, void *check)
{
	if (!check)
		return (free_phl(phl, 'm'));
	return (NULL);
}
