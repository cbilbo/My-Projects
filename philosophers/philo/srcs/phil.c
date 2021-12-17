/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:32:26 by cbilbo            #+#    #+#             */
/*   Updated: 2021/09/09 16:53:28 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/phil.h"

int	main(int ac, char **av)
{
	t_phl	*phl;

	phl = start_phl(ac, av);
	if (phl)
	{
		start_threads(phl);
		free_phl(phl, 0);
	}
	return (0);
}
